# ⚙️ Flux: Financial Management System

<p align="left">
  <img src="https://img.shields.io/badge/Status-In%20Development-ffb347?style=for-the-badge&logo=git&logoColor=white" />
  <img src="https://img.shields.io/badge/Language-C%2B%2B20-4facfe?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img src="https://img.shields.io/badge/Interface-TUI-52b788?style=for-the-badge&logo=gnometerminal&logoColor=white" />
  <img src="https://img.shields.io/badge/Platform-Universal-ce9ffc?style=for-the-badge&logo=target&logoColor=white" />
</p>

**Flux** is a high-performance financial system powered by a robust **C++ backend**. Designed with a "Systems-First" philosophy, Flux treats financial data with the precision of a low-level engine. By strictly decoupling the core logic from the interface, it provides a high-speed **Textual User Interface (TUI)** that delivers extreme memory efficiency and data integrity without the bloat of traditional graphical frameworks.

---

## ✨ My Inspiration

Flux isn't just a project to me, it’s actually my very first 'Deep Dive' into the world of programming! I built this as my first complete C++ project because I was tired of just scratching the surface. I wanted to dive deep, break things, and understand what’s actually happening under the hood of a computer.

This project became the foundation of everything I know today. It’s what inspired me to keep exploring, keep building, and eventually dive head-first into the world of Systems and Software Engineering. It’s definitely come a long way from my early experiments, and looking at this code always reminds me of how much I’ve leveled up since I first started typing `int main()`. It’s messy in the memories, but clean in the code!

---

## 🚀 Quick Start

**Clone the repository:**

```bash
git clone https://github.com/nadasshawer/financial-ledger-engine.git
cd financial-ledger-engine
```

**Build the Engine:**

```bash
make
```

**Launch the TUI:**

```bash
./bin/flux
```

---

## 📁 Project Structure

```txt
├── include/                 # Blueprints: All Header Files (.h)
│   ├── auth/                # registration.h, user_info.h
│   ├── core/                # globals.h
│   ├── models/              # classes.h (Transaction, Expense, Income)
│   ├── utils/               # math_utils.h, datetime.h, text_utils.h
│   └── validation/          # validation.h
│
├── src/                     # The Engine: Core C++ Logic (.cpp)
│   ├── auth/                # User authentication implementation
│   ├── core/                # Main TUI Loop & State Management
│   ├── models/              # Finance class logic & inheritance
│   └── validation/          # Strict memory-efficient checks
│
├── docs/                    # Technical Documentation
│   └── architecture.md      # TUI design & data flow strategy
│
├── bin/                     # Compiled binaries
├── Makefile                 # Automated build instructions
└── README.md                # You're here!
```

---

## 🛠️ Key Features

### 1. Terminal-Native Interface (TUI)

- Flux utilizes a professional terminal interface that provides real-time feedback and navigation.
- By staying in the command line, Flux ensures low system resource usage and high responsiveness.

### 2. Strict Memory-Efficient Validation

Every piece of data passes through a **C++ Validation Layer** before being processed:

- **Pass-by-Reference:** All string inputs are handled via `const std::string&` to prevent unnecessary memory copies.
- **Automatic Sanitization:** Built-in utilities handle currency rounding, name capitalization, and date validation (including leap-year logic).

### 3. Modular "Headless" Design

- The C++ core is entirely decoupled from the TUI.
- The logic is built using functions and classes that return data, allowing the engine to be portable and easily integrated into different environments in the future.

---

## 🏗️ Technical Architecture

Flux follows a modular design to separate concerns:

- **The Core Engine:** The source of truth for all business rules, mathematical calculations, and data models.
- **The TUI Controller:** Manages the terminal state, user input loops, and data display.
- **The Persistence Layer:** Manages how financial records are stored and retrieved (Local file system/SQLite).

---

## 📈 Roadmap

- [x] **Milestone 1:** Core Inheritance & Memory-Efficient Setters
- [x] **Milestone 2:** Refactoring Engine for "Headless" Logic
- [ ] **Milestone 3:** ANSI-based TUI Menu Implementation
- [ ] **Milestone 4:** Local Persistence Layer (File I/O or SQLite)

---

## 💡 Pro-Tips

**Optimizing the Build**

- When modifying the core engine or the UI logic, simply run `make` to recompile. The build system is configured to only recompile the changed modules, keeping your development cycle fast.
