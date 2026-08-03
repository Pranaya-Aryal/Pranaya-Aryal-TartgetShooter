CXX := g++
CXXFLAGS := -std=c++17 -Wall -I"$(RAYLIB_PATH)/src"
LDFLAGS := -L"$(RAYLIB_PATH)/src" -lraylib -lopengl32 -lgdi32 -lwinmm

SRC := main.cpp Game.cpp GameDraw.cpp Target.cpp
OBJ := $(SRC:.cpp=.o)
TARGET := main.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@del /Q $(OBJ) $(TARGET) 2>nul

.PHONY: all clean
