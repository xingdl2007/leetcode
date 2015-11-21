GTEST_HOME := /usr/local/gtest
CXXFLAGS := -I$(GTEST_HOME)/include
LDFLAGS := -lgtest_main -lgtest -lpthread -L$(GTEST_HOME)/lib 

all: malloc.o unittest.o
	g++ -o mempool.out malloc.o unittest.o $(LDFLAGS) 
	
malloc.o: malloc.cc malloc.h
	g++ -c malloc.cc -o malloc.o $(CXXFLAGS) 
	
unittest.o: unittest.cc malloc.h
	g++ -c unittest.cc -o unittest.o $(CXXFLAGS) 

clean:
	rm -rf *.o mempool.out