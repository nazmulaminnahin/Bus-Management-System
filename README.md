# Bus Management System (C Project)

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Compiler](https://img.shields.io/badge/Compiler-GCC-orange.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20PowerShell-0078D4.svg)
![Architecture](https://img.shields.io/badge/Architecture-Modular-green.svg)

This Bus Management System was built as a practical C-programming project to simulate real-world ticket counter operations. It handles everything from seat layout visualization and real-time ticket booking to cancellation refunds using C file handling. Designed with a structured multi-file architecture, clean console UI, and an extended login mechanism featuring password recovery.

## Default Login Credentials
If you are testing or running the project, use these default credentials to log in:
- **Username:** `admin`
- **Password:** `12345678`

*(Note: Entering the wrong password 3 times continuously will trigger the password recovery).*

## Features Overview
- **View Bus List:** Check out the available bus operators (Hanif, Shyamoli, Green Line, etc.).
- **Book Tickets:** Select a bus, check available seats in real-time, enter passenger details, and calculate total fare.
- **Seat Status Board:** Interactive visual layout showing booked seats versus empty seats (`Empty` vs Passenger Name).
- **Cancel Booking:** Cancel tickets by seat number and process refunds instantly.
- **Security & Recovery:** Secure password masking with `*` and a built-in forgot password flow.

## Project Structure
The project supports both modular execution and single-file compilation:
- `main.c` - Entry point and main menu controller.
- `login_page.c` - Handles authentication and password resetting.
- `bus_operations.c` - Core logic for booking, viewing status, and cancellations.
- `bus.h` - Shared header file containing function prototypes and global variables.
- `bus_management_system.c` - Combined single-file version containing the complete codebase.

## How to Compile and Run
Make sure you have the GCC compiler installed on your system. Open your terminal or PowerShell inside the project folder and run either of the following commands:

**Option 1: Compile modular files (Recommended)**
```powershell
gcc main.c login_page.c bus_operations.c -o main
.\main.exe
```
**Option 2: Compile combined single file**
```powershell
gcc bus_management_system.c -o main
.\main.exe
```