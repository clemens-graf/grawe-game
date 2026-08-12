# Standard Compiler und Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2

# Betriebssystem automatisch erkennen
ifeq ($(OS),Windows_NT)
    # --- WINDOWS ---
    RAYLIB_PATH = C:/raylib/raylib/src
    CXXFLAGS += -I$(RAYLIB_PATH)
    LIBS = -L$(RAYLIB_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm
    EXT = .exe
    CLEAN_CMD = del /Q grawe_pong\*.exe grawe_snake\*.exe 2>nul
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        # --- LINUX ---
        LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
        EXT =
        CLEAN_CMD = rm -f grawe_pong/pong grawe_snake/snake
    endif
    ifeq ($(UNAME_S),Darwin)
        # --- MACOS ---
        CXX = clang++
        CXXFLAGS += -I/opt/homebrew/include
        LIBS = -L/opt/homebrew/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
        EXT =
        CLEAN_CMD = rm -f grawe_pong/pong grawe_snake/snake
    endif
endif

# --- SPIEL TARGETS ---

# 1. PONG
PONG_SRC = grawe_pong/grawe_pong.cpp
PONG_OUT = grawe_pong/grawe_pong$(EXT)

pong: $(PONG_SRC)
	$(CXX) $(CXXFLAGS) $(PONG_SRC) -o $(PONG_OUT) $(LIBS)

run-pong: pong
	./$(PONG_OUT)

# 2. SNAKE
SNAKE_SRC = grawe_snake/grawe_snake.cpp
SNAKE_OUT = grawe_snake/grawe_snake$(EXT)

snake: $(SNAKE_SRC)
	$(CXX) $(CXXFLAGS) $(SNAKE_SRC) -o $(SNAKE_OUT) $(LIBS)

run-snake: snake
	./$(SNAKE_OUT)

# Aufräumen
clean:
	$(CLEAN_CMD)