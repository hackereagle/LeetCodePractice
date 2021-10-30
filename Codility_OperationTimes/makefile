CC          = g++
CFLAGS      = -Wall
CXXFLAGS        =  -c -g -Ddebug
BIN_DIR     = .

all: TestOperationTimes
	make clean

source: source.cpp
	$(CC) $(CXXFLAGS) source.cpp -I./ -o $(CXXFLAGS) $(BIN_DIR)/source.o

OperationTimes: OperationTimes.cpp
	$(CC)  $(CXXFLAGS) OperationTimes.cpp -I./ -o $(BIN_DIR)/OperationTimes.o

TestOperationTimes: $(BIN_DIR)/source.o $(BIN_DIR)/OperationTimes.o
	$(CC) $(BIN_DIR)/source.o $(BIN_DIR)/OperationTimes.o -o $(BIN_DIR)/TestOperationTimes

clean:
	rm $(BIN_DIR)/*.o