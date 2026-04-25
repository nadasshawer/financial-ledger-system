# ⚙️ Flux: Financial Management System

<p align="left">
  <img src="https://img.shields.io/badge/Status-In%20Development-orange?style=for-the-badge&logo=git" />
</p>

**LedgerCore** is a hybrid financial management system built with a "Systems-First" philosophy. It features a compiled C++ core for precision calculations and strict data validation, seamlessly bridged to a Node.js dashboard. It’s designed for users who need a robust, memory-efficient way to manage wealth without the overhead of standard monolithic apps.

_This project is in its early stages. The C++ core is stable, but the Node.js Bridge is still being developed._

## 🚀 Quick Start

**Clone the repository:**

```bash
git clone https://github.com/nadasshawer/financial-ledger-engine.git
cd financial-ledger-engine
```

**Build the Engine:** This will use the Makefile to compile the C++ source and prepare the binaries for the bridge.

```bash
make
```

**Launch the Dashboard:**

```bash
cd web
npm install
npm start
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
│   ├── models/              # Finance class logic & inheritance
│   └── validation/          # Strict memory-efficient checks
│
├── native/                  # The Translator: JavaScript-to-C++ Bridge
│   └── bridge/              # validation_bridge.cpp (Node Addon)
│
├── web/                     # The Dashboard: Node.js & UI
│   ├── public/              # Modern CSS & Client-side JS
│   └── views/               # EJS Templates for data rendering
│
├── docs/                    # Technical Documentation
│   └── bridging/            # Bridging strategy + architectural challenges
│
├── bin/                     # Compiled binaries
├── Makefile                 # Automated build instructions
└── README.md                # You're here!
```

---

## 🛠️ Key Features

### 1. Hybrid Architecture (The Bridge)

Unlike standard web apps, LedgerCore utilizes a **Native C++ Bridge**. This allows the Node.js frontend to offload heavy business logic and financial calculations to a compiled binary, ensuring near-instant execution and type-safety at the engine level.

### 2. Strict Memory-Efficient Validation

Every piece of data passes through a **C++ Validation Layer** before it ever touches the database:

- **Pass-by-Reference:** All string inputs are handled via `const std::string&` to prevent unnecessary memory copies.
- **Automatic Sanitization:** Built-in utils capitalize names, round currency to exactly two decimal places, and validate date ranges against a leap-year-aware calendar.

### 3. Hierarchical Financial Models

The system uses a clean inheritance structure to maintain data integrity:

- **Transaction (Base):** Handles core metadata (Date, Category, Description).
- **Expense & Income (Derived):** Specialized models for tax rates, payment frequencies, and budget allocations.

### 4. Headless-Ready Design

The C++ core is "Silent"; it contains no `std::cout` or UI dependencies. This means the engine can be ported to a CLI, a mobile app, or a desktop interface without changing a single line of logic code.

---

## 🏗️ Technical Architecture

LedgerCore follows a modular design to separate concerns:

- **The Engine (C++):** The source of truth for all business rules and math.
- **The Translator (extern "C"):** A thin wrapper that prevents C++ name mangling so JavaScript can invoke native methods.
- **The Persistence (SQLite):** Ensures financial records are reliable, relational, and ACID-compliant.
- **The View (Node/EJS):** A responsive interface for real-time visualization of the engine's output.

---

## 📋 Data Flow: The Path of a "Click"

1.  **UI:** User clicks "Add Expense" on the dashboard.
2.  **Browser:** Sends form data to the Node.js server.
3.  **Bridge:** Node.js triggers the bridge, converting JS types to C++ types.
4.  **Engine:** The C++ core validates the data and instantiates an `Expense` object.
5.  **Database:** The engine commits the validated record to the local ledger.
6.  **Response:** The UI refreshes with the new calculation sent back from the engine.

---

## 📈 Roadmap

- [x] **Milestone 1:** Core Inheritance & Memory-Efficient Setters
- [ ] **Milestone 2:** Native Bridge Implementation & Type Conversion
- [ ] **Milestone 3:** SQLite Integration & Persistence Layer
- [ ] **Milestone 4:** Full Dynamic Reporting & Analytics Dashboard

---

## 💡 Pro-Tips

**Optimizing the Build**
If you make changes to the C++ logic, you don't need to restart the Node server. Just run `make` in the root directory to recompile the binary, and the bridge will automatically pick up the new logic on the next request.
