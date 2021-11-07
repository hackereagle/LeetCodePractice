CC          = g++
CFLAGS      = -Wall
CXXFLAGS    =  -c -g -Ddebug
BIN_DIR     = .
INCS        = -I./ -I../CommomModules/

all: TestFindMinAmplitude
	make clean

main: main.cpp
	$(CC) $(CXXFLAGS) main.cpp $(INCS) -o $(BIN_DIR)/main.o

FindMinAmplitude: FindMinAmplitude.cpp
	$(CC)  $(CXXFLAGS) FindMinAmplitude.cpp $(INCS) -o $(BIN_DIR)/FindMinAmplitude.o

TestFindMinAmplitude: $(BIN_DIR)/main.o $(BIN_DIR)/FindMinAmplitude.o
	$(CC) $(BIN_DIR)/main.o $(BIN_DIR)/FindMinAmplitude.o -o $(BIN_DIR)/TestFindMinAmplitude

clean:
	rm $(BIN_DIR)/*.o