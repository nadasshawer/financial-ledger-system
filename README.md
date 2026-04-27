# ⚙️ Flux: Financial Budget Tracker

<p align="left">
  <img src="https://img.shields.io/badge/Language-C%2B%2B20-4facfe?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img src="https://img.shields.io/badge/Interface-TUI-52b788?style=for-the-badge&logo=gnometerminal&logoColor=white" />
  <img src="https://img.shields.io/badge/Platform-Cross--Platform-ce9ffc?style=for-the-badge&logo=target&logoColor=white" />
</p>

**Flux** is a high-performance financial tracking engine powered by **C++20**. Designed with a "Systems-First" philosophy, it treats personal finance with the precision of a low-level engine. By utilizing a **Unified Frame Architecture**, Flux provides a seamless, single-page GUI experience directly inside the terminal via the **FTXUI library**, delivering extreme memory efficiency without the bloat of traditional frameworks.

---

## 🖼️ System Storyboard

<table style="width: 100%; border-collapse: collapse; border: none;">
  <tr style="border: none;">
    <td align="center" style="border-bottom: 1px solid #333; border-right: 1px solid #333; padding: 20px; width: 50%;">
      <b>User Registration Dashboard</b><br><br>
      <img src="images/image.png" width="400"><br><br>
    </td>
    <td align="center" style="border-bottom: 1px solid #333; padding: 20px; width: 50%;">
      <b>Login Page</b><br><br>
      <img src="images/image-1.png" width="400"><br><br>
    </td>
  </tr>
  <tr style="border: none;">
    <td align="center" style="border-bottom: 1px solid #333; border-right: 1px solid #333; padding: 20px;">
      <b>Main Menu Navigator</b><br><br>
      <img src="images/image-6.png" width="400"><br><br>
    </td>
    <td align="center" style="border-bottom: 1px solid #333; padding: 20px;">
      <b>Revenue/Income Tracker</b><br><br>
      <img src="images/image-7.png" width="400"><br><br>
    </td>
  </tr>
  <tr style="border: none;">
    <td align="center" style="border-right: 1px solid #333; padding: 20px;">
      <b>Expense Tracker</b><br><br>
      <img src="images/image-8.png" width="400"><br><br>
    </td>
    <td align="center" style="padding: 20px;">
      <b>Financial Report</b><br><br>
      <img src="images/image-9.png" width="400"><br><br>
    </td>
  </tr>
</table>

---

## 🛠️ Tech Stack & Core Libraries

**Core Logic & Language**
<p align="left">
  <img src="https://img.shields.io/badge/C%2B%2B20-Standard-4facfe?style=flat-square" />
  <img src="https://img.shields.io/badge/STL-Containers-4facfe?style=flat-square" />
  <img src="https://img.shields.io/badge/CMake-3.10+-4facfe?style=flat-square" />
</p>

**Interface & UX (TUI)**
<p align="left">
  <img src="https://img.shields.io/badge/FTXUI-Library-52b788?style=flat-square" />
  <img src="https://img.shields.io/badge/UI-Component--Based-52b788?style=flat-square" />
  <img src="https://img.shields.io/badge/UX-Event--Driven-52b788?style=flat-square" />
</p>

**System Architecture**
<p align="left">
  <img src="https://img.shields.io/badge/OOP-Modular-ce9ffc?style=flat-square" />
  <img src="https://img.shields.io/badge/Logic-Functional-ce9ffc?style=flat-square" />
  <img src="https://img.shields.io/badge/State-Management-ce9ffc?style=flat-square" />
</p>

---

## ✨ Key Features

### 1. Unified Frame Interface

Unlike standard terminal apps, Flux uses a **Single-Page Application (SPA)** approach. The main system border stays static while the internal content (Income, Expense, Ledger) swaps out dynamically, creating a true GUI feel.

### 2. Precise Financial Ledger

- **Real-Time Auditing:** Automatically calculates Net Position using high-precision doubles.
- **Formatted Reporting:** Generates a structured accounting table with column alignment and 2-decimal point enforcement.

### 3. Secure Gateway

- **Strict Validation:** Validates birth years (1900-2026) and enforces password complexity.
- **Identity Matching:** Cross-references session credentials to prevent unauthorized access.

### 4. Interactive UX

- **Mouse Support:** Full mouse integration for menu selection and button clicks.
- **Global Hotkeys:** Quick emergency exit and navigation via keyboard interrupts (`Q` / `ESC`).

---

## 🚀 Quick Start

**Clone the repository:**

```bash
git clone [https://github.com/nadasshawer/flux-budget-tracker.git](https://github.com/nadasshawer/flux-budget-tracker.git)
cd flux-budget-tracker
```

**Build the Engine:**

```bash
mkdir build && cd build
cmake ..
make
```

**Launch the TUI:**

```bash
./flux_engine
```

---

## 📁 Project Structure

```txt
├── include/                 # Blueprints: All Header Files (.h)
│   ├── auth/                # registration.h, user_info.h
│   ├── core/                # menu_handler.h, navigation logic
│   ├── models/              # report.h (Transaction history)
│   └── validation/          # input validation & regex
│
├── src/                     # The Engine: Core C++ Logic (.cpp)
│   ├── auth/                # Secure login & registration logic
│   ├── core/                # Unified Frame TUI & State Management
│   ├── models/              # Accounting logic & data structures
│   └── validation/          # Strict year & password checks
│
├── images/                  # Storyboard screenshots
├── CMakeLists.txt           # Build configuration
└── README.md                # You're here!
```

---

## 📈 Project Roadmap

- [x] **Milestone 1:** Build the core C++ classes (Transaction, User, etc.) to hold all the data
- [x] **Milestone 2:** Create the "Helper" functions and validation logic to make sure the inputs are correct
- [x] **Milestone 3:** Write all the Setters and Getters to move data safely between the classes
- [x] **Milestone 4:** Install the FTXUI library and get the CMake build system to actually recognize it
- [x] **Milestone 5:** Build the actual TUI screens and connect the buttons to the  C++ logic
- [x] **Milestone 6:** Fix the focus bugs and navigation so the Mouse and Escape keys work perfectly

---

## 💡 Pro-Tip

For the smoothest mouse experience and best color rendering, run Flux in **Windows Terminal** or **VS Code's Integrated Terminal**.
