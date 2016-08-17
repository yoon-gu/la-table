ifeq ($(CC),)
    CC = gcc
endif
ifeq ($(CXX),)
    CXX = g++
endif
LFLAG = -lstdc++
FFLAG = -fopenmp
OPTFLAG = -O3

.PHONY: clear

all: main.o basic_operation.o
	./main.o
	./basic_operation.o
	
main.o: main.cpp
	$(CXX) $(OPTFLAG) main.cpp $(LFLAG) -o main.o

basic_operation.o: basic_operation.cpp
	$(CXX) $(OPTFLAG) basic_operation.cpp $(LFLAG) -o basic_operation.o

test:
	$(CXX) -fprofile-arcs -ftest-coverage main.cpp -lboost_unit_test_framework -o main.o
	./main.o
	gcov main.cpp

clear:
	rm *.o
	rm *.gc*