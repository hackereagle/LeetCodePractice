CC          = g++
BIN_DIR     = .

all: TestOperationTimes
	make clean

source: source.cpp
	$(CC) -c source.cpp -I./ -o $(BIN_DIR)/source.o

OperationTimes: OperationTimes.cpp
	$(CC) -c OperationTimes.cpp -I./ -o $(BIN_DIR)/OperationTimes.o

TestOperationTimes: $(BIN_DIR)/source.o $(BIN_DIR)/OperationTimes.o
	$(CC) $(BIN_DIR)/source.o $(BIN_DIR)/OperationTimes.o -o $(BIN_DIR)/TestOperationTimes

clean:
	rm $(BIN_DIR)/*.o