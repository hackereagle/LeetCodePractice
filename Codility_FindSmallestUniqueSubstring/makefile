CC          = g++
CFLAGS      = -Wall
CXXFLAGS    =  -c -g -Ddebug
BIN_DIR     = .

all: TestFindSmallestUniqueSubstring
	make clean

main: main.cpp
	$(CC) $(CXXFLAGS) main.cpp -I./ -o $(CXXFLAGS) $(BIN_DIR)/main.o

FindSmallestUniqueSubstring: FindSmallestUniqueSubstring.cpp
	$(CC)  $(CXXFLAGS) FindSmallestUniqueSubstring.cpp -I./ -o $(BIN_DIR)/FindSmallestUniqueSubstring.o

TestFindSmallestUniqueSubstring: $(BIN_DIR)/main.o $(BIN_DIR)/FindSmallestUniqueSubstring.o
	$(CC) $(BIN_DIR)/main.o $(BIN_DIR)/FindSmallestUniqueSubstring.o -o $(BIN_DIR)/TestFindSmallestUniqueSubstring

clean:
	rm $(BIN_DIR)/*.o