ifeq ($(CC),)
    CC = gcc
endif
ifeq ($(CXX),)
    CXX = g++
endif
LFLAG =
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
	$(CXX) -fprofile-arcs -ftest-coverage basic_operation.cpp -lboost_unit_test_framework -o basic_operation.o
	$(CXX) -fprofile-arcs -ftest-coverage matrix_factory.cpp -lboost_unit_test_framework -o matrix_factory.o
	./main.o
	./basic_operation.o
	./matrix_factory.o
	gcov main.cpp
	gcov basic_operation.cpp
	gcov matrix_factory.cpp

la: matrix_factory.o

matrix_factory.o: matrix_factory.cpp
	$(CXX) $(OPTFLAG) matrix_factory.cpp $(LFLAG) -o matrix_factory.o
	./matrix_factory.o


clear:
	rm *.o
	rm *.gc*