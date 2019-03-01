CXX = g++

CXXFLAGS= -std=c++11 -Wall -g

prog2: SplayTree.o main.o 
	${CXX} $^ -o $@

clean:
	/bin/rm -f *.o prog2