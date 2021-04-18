CPP = g++
CPPFLAGS = -Wall -std=c++14
BIN = test test2

.PHONY: all clean

all: $(BIN)

test: main.cc
	$(CPP) $(CPPLAGS) -o $@ $<

test2: test.cc
	$(CPP) $(CPPFLAGS) -o $@ $<

clean:
	$(RM) $(BIN)
