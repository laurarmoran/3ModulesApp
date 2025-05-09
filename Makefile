CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -pthread -Iinclude
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/app

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)
	@echo "Done $(TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/*.h
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	@echo
	@$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*

rebuild: clean all
