import express from "express";
import path from "path"; // This helps find folders on your computer
import { load, DataType } from "ffi-rs";

const app = express();
const port = 3000;

// 1. Tell Express where your EJS files are
app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));

// 2. Tell Express how to read the data coming from your HTML form
app.use(express.urlencoded({ extended: true }));

// 3. Your "Home" route - This shows the index.ejs page
app.get("/", (req, res) => {
  res.render("index", { message: null });
});

// 4. Your "Action" route - This is where the form sends data
app.post("/add-expense", (req, res) => {
  // Pull the data out of the form
  const { name, amount, date } = req.body;

  // For now, let's just log it to make sure the UI works!
  console.log("Form received:", name, amount, date);

  // We will add the C++ Bridge call here in the next step
  res.render("index", {
    message: `Received ${name} for $${amount}. Ready to send to C++!`,
  });
});

app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});
