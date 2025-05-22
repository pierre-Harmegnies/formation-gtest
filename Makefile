CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17
SRC_DIR = source
INC_DIR = include
OBJ_DIR = build/objects
BIN_DIR = build/bin
TEST_DIR = test

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
EXEC = $(BIN_DIR)/jeu

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.test.o,$(TEST_SOURCES))
TEST_EXEC = $(BIN_DIR)/tests

all: $(BIN_DIR) $(OBJ_DIR) $(EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# --- Tests GoogleTest ---
test: $(TEST_EXEC)
	$(TEST_EXEC)

$(OBJ_DIR)/%.test.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(TEST_EXEC): $(OBJ_DIR)/test_Arme.test.o $(OBJ_DIR)/test_Personnage.test.o $(OBJ_DIR)/Arme.o $(OBJ_DIR)/Personnage.o $(OBJ_DIR)/SuperBonus.o | $(BIN_DIR)
	mkdir -p $(BIN_DIR)
	$(CXX) -I$(INC_DIR) -Wall -Wextra -std=c++17 $^ -lgtest -lgtest_main -lgmock -pthread -o $(TEST_EXEC)

clean:
	rm -rf build/objects/*.o build/bin/jeu build/bin/tests

.PHONY: all clean test
