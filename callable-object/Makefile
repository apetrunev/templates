CPP = g++
CPPFLAGS = -Wall -std=c++14
BIN = test

.PHONY: all clean

all: $(BIN)

test: main.cc
	$(CPP) $(CPPLAGS) -o $@ $<

clean:
	$(RM) $(BIN)
