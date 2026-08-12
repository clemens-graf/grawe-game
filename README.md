# GRAWE Minigame Collection

This repository contains small games developed during my IT internship at **GRAWE** in August 2026. 

The development took place in consultation with my supervisor and after all assigned tasks in my core area (IT project management) were successfully completed.

---

## Included Games

### 1. Pong (GRAWE Edition)
A classic Pong clone featuring a GRAWE-inspired design, programmed in C++ using the Raylib library.

![Pong Gameplay](assets/pong_gameplay.gif)

<!-- ### 2. Jump And Insurance (GRAWE Edition) -->

---

## Compilation and Execution

The project utilizes a cross-platform `Makefile` that automatically detects the operating system (Windows, macOS, Linux) and applies the appropriate build parameters.

### Prerequisites
The following components are required for successful compilation:
* A C++ compiler (`g++` for Windows/Linux, `clang++` for macOS)
* A Make tool (`mingw32-make` on Windows, `make` on Linux/macOS)
* The **[Raylib library](https://www.raylib.com/)** (On Windows, the default path `C:/raylib/raylib/src` is expected; on macOS, an installation via Homebrew is required).

### Instructions
To run the games, open a terminal in the root `grawe-game` folder. The following commands will build the source code and automatically start the respective game:

**On Windows:**
```powershell
mingw32-make run-pong
mingw32-make run-snake
```

**On macOS/Linux:**

```bash
make run-pong
make run-snake
```
