CPP = g++
CPPFLAGS = -Wall -std=c++14
CPPLIBS =
BIN = stack

.PHONY: all clean

all: $(BIN)

COMPILE := $(CPP) $(CPPFALGS)

stack: stack.cc Stack.h
	$(COMPILE) -o $@ $^

clean:
	$(RM) -v $(BIN) *.o
