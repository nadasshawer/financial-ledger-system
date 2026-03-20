import express from "express";
import { close } from "ffi-rs";
import { join } from "path";
import { callAddFunction } from "./ffi_method";

const app = express();

app.set("view engine", "ejs");
app.set("views", join(process.cwd(), "src", "views"));
app.use(express.urlencoded());

app.get("/", (req, res) => {
  const calculation = res.app.locals?.result || { a: "", b: "", result: "" };
  res.render("index", { calculation });
});

app.post("/", async (req, res) => {
  const a = Number(req.body.a);
  const b = Number(req.body.b);
  const result = await callAddFunction(a, b);
  res.app.locals.result = { a, b, result };
  res.redirect("/");
});

function exit(code: number): void {
  close("math");
  process.exit(code);
}
process.on("SIGINT", () => exit(0));
process.on("SIGTERM", () => exit(0));

app.listen(3000, () => {
  console.log(`Server running`);
});
