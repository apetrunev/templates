CPP := g++
CPPFLAGS := -Wall -O0 -std=c++17
CPPLIBS :=

HEADERS = ../Stack.h
SRC = main.cc
BIN = test

.PHONY: all clean

all: $(BIN)

COMPILE := $(CPP) $(CPPFLAGS)

test: main.cc $(HEADERS) 
	$(COMPILE) -o $@ main.cc

clean:
	$(RM) $(BIN)
