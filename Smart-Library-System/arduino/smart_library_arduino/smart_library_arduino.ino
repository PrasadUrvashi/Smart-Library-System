#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

// WiFi credentials
#define WIFI_SSID //"Wi-FI Name"
#define WIFI_PASSWORD //"WIFI password"

// Firebase credentials
#define API_KEY //"api key of firebase"
#define DATABASE_URL //"firebse database url"
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long prevMillis = 0;
bool signupOK = false;

// Seat 1
const int ir1 = 34;
const int ledGreen1 = 25;
const int ledRed1 = 26;

// Seat 2
const int ir2 = 35;
const int ledGreen2 = 27;
const int ledRed2 = 14;

void setup() {
  Serial.begin(115200);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ledGreen1, OUTPUT);
  pinMode(ledRed1, OUTPUT);
  pinMode(ledGreen2, OUTPUT);
  pinMode(ledRed2, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi Connected");

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("Firebase signup successful");
    signupOK = true;
  } else {
    Serial.printf("Signup failed: %s\n", config.signer.signupError.message.c_str());
  }

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  Serial.println("Firebase initialized");
}

void loop() {
  if (Firebase.ready() && signupOK && (millis() - prevMillis > 1000)) {
    prevMillis = millis();
    updateSeat("Seat1", ir1, ledGreen1, ledRed1);
    updateSeat("Seat2", ir2, ledGreen2, ledRed2);
  }
}

void updateSeat(String seatName, int irPin, int greenLED, int redLED) {
  int sensorValue = digitalRead(irPin);
  bool autoDetected = (sensorValue == LOW); // object detected
  bool reservedByApp = false;

  // Read reservedByApp (string or boolean)
  if (Firebase.RTDB.get(&fbdo, "Seats/" + seatName + "/reservedByApp")) {
    String type = fbdo.dataType();
    if (type == "string") {
      reservedByApp = (fbdo.stringData() == "true");
    } else if (type == "boolean") {
      reservedByApp = fbdo.boolData();
    }
  }

  // LED logic
  if (reservedByApp || autoDetected) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    Firebase.RTDB.setString(&fbdo, "Seats/" + seatName + "/Status", "reserved");
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    Firebase.RTDB.setString(&fbdo, "Seats/" + seatName + "/Status", "available");
  }

  // Always update autoDetected value in Firebase
  Firebase.RTDB.setBool(&fbdo, "Seats/" + seatName + "/autoDetected", autoDetected);

  Serial.print(seatName);
  Serial.print(" | IR: ");
  Serial.print(autoDetected);
  Serial.print(" | App: ");
  Serial.print(reservedByApp);
  Serial.println();
}