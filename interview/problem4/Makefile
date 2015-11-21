GTEST_HOME := /usr/local/gtest
CXXFLAGS := -I$(GTEST_HOME)/include
LDFLAGS := -lgtest_main -lgtest -lpthread -L$(GTEST_HOME)/lib 

all:
	g++ problem4.cc $(CXXFLAGS) $(LDFLAGS) 

clean:
	rm -rf *.o a.out
