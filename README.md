# GRAWE Minigame Collection

Dieses Repository enthält kleine Spiele, die im Laufe meines IT-Praktikums bei der **GRAWE** im August 2026 entstanden sind. 

Die Entwicklung erfolgte nach Absprache mit meinem Vorgesetzten und nachdem alle mir zugeteilten Aufgaben in meinem Kernbereich (IT-Projektmanagement) erfolgreich abgeschlossen waren.

---

## Enthaltene Spiele

### 1. Pong (GRAWE Edition)
Ein klassischer Pong-Klon im GRAWE-Design, programmiert in C++ unter Verwendung der Raylib-Bibliothek.

![Preview of GRAWE Pong](assets/grawe_pong_preview.png)

<!-- ### 2. Jump And Insurance (GRAWE Edition) -->

---

## Kompilierung und Ausführung

Das Projekt nutzt ein plattformübergreifendes `Makefile`, welches das Betriebssystem (Windows, macOS, Linux) automatisch erkennt und die entsprechenden Build-Parameter anwendet.

### Voraussetzungen
Für die erfolgreiche Kompilierung sind folgende Komponenten erforderlich:
* Ein C++ Compiler (`g++` für Windows/Linux, `clang++` für macOS)
* Ein Make-Tool (`mingw32-make` auf Windows, `make` auf Linux/macOS)
* Die **[Raylib-Bibliothek](https://www.raylib.com/)** (Unter Windows wird der Standardpfad `C:/raylib/raylib/src` erwartet, unter macOS wird eine Installation via Homebrew vorausgesetzt).

### Anleitung
Zur Ausführung des Spiels muss ein Terminal im entsprechenden Projektordner (z.B. `grawe_pong`) geöffnet werden. Der folgende Befehl baut den Quellcode und startet das Spiel im Anschluss automatisch:

**Unter Windows:**
```powershell
mingw32-make run
```

**Unter macOS/Linux:**
```powershell
make run
```