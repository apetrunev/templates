CPP=g++
CPPFLAGS=-Wall -std=c++14
SRC=main.cc
BIN=test

.PHONY: all clean

all: $(BIN)

COMPILE:=$(CPP) $(CPPFLAGS)

test: main.cc
	$(COMPILE) -o $@ $<

clean:
	$(RM) $(BIN) *.o
