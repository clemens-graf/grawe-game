# Standard Compiler und Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2
SRC = main.cpp
TARGET = main

# Betriebssystem automatisch erkennen
ifeq ($(OS),Windows_NT)
    # --- WINDOWS ---
    RAYLIB_PATH = C:/raylib/raylib/src
    CXXFLAGS += -I$(RAYLIB_PATH)
    LIBS = -L$(RAYLIB_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm
    TARGET := $(TARGET).exe
    CLEAN_CMD = del /Q $(TARGET)
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        # --- LINUX ---
        LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
        CLEAN_CMD = rm -f $(TARGET)
    endif
    ifeq ($(UNAME_S),Darwin)
        # --- MACOS ---
        CXX = clang++
        CXXFLAGS += -I/opt/homebrew/include
        LIBS = -L/opt/homebrew/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
        CLEAN_CMD = rm -f $(TARGET)
    endif
endif

# Spiel kompilieren
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Bauen und direkt starten
run: all
	./$(TARGET)

# Kompilierte Datei löschen
clean:
	$(CLEAN_CMD)