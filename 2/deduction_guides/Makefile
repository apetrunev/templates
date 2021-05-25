CPP := g++
CPPFLAGS := -Wall -O0 
CPPLIBS :=

SRC = main.cc
BIN = test

.PHONY: all clean

all: $(BIN)

COMPILE := $(CPP) $(CPPFLAGS)

test: main.cc
	$(COMPILE) -o $@ main.cc

clean:
	$(RM) $(BIN)
