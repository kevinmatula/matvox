# Compiler
CXX = g++
CXXFLAGS = -std=c++20 ## -Wall -Wextra

# Source files
SRC = $(wildcard *.cpp src/Position/*.cpp src/Object/*.cpp)

# Output executable
TARGET = matvox

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean up object files and executable
clean:
	rm -f $(TARGET)
