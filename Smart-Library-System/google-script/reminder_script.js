function sendReminders() {
  const firebaseUrl = "firebase url";

  try {
    const response = UrlFetchApp.fetch(firebaseUrl);
    const data = JSON.parse(response.getContentText());
    const today = new Date();
    const todayStr = Utilities.formatDate(today, "GMT+5:30", "yyyy/MM/dd");

    let sentCount = 0;
    let skippedCount = 0;

    for (const id in data) {
      const book = data[id];
      if (!book) continue;

      const borrowerEmail = clean(book.borrowerEmail);
      const borrowerName  = clean(book.borrower);
      const dueDate       = clean(book.dueDate);
      const title         = clean(book.title);
      const status        = clean(book.status);

      if (!borrowerEmail || !borrowerEmail.includes("@")) {
        skippedCount++;
        continue;
      }

      if (status === "borrowed" && dueDate) {
        const daysLeft = dateDiff(dueDate, todayStr);

        if (daysLeft <= 2) {
          const subject = "📚 Library Book Due Date Reminder";
          const message =
`Dear ${borrowerName || "Student"},

This is a reminder that the book "${title}" you borrowed is due on ${dueDate}.
Please return it to the library before or on the due date to avoid any penalty.

Thank you,
Library Management System`;

          MailApp.sendEmail(borrowerEmail, subject, message);
          sentCount++;
        } else {
          skippedCount++;
        }
      }
    }

    Logger.log(`Reminders sent: ${sentCount}, Skipped: ${skippedCount}`);
  } catch (error) {
    Logger.log("Error: " + error);
  }
}

// --- Helper functions ---
function clean(value) {
  if (!value) return "";
  return String(value).replace(/^"+|"+$/g, "").replace(/\\/g, "");
}

function dateDiff(due, today) {
  const d1 = new Date(due);
  const d2 = new Date(today);
  return Math.floor((d1 - d2) / (1000 * 60 * 60 * 24));
}
