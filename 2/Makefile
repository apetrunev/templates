CPP = g++
CPPFLAGS = -Wall -std=c++14
CPPLIBS =
BIN = stack

.PHONY: all clean

all: $(BIN)

COMPILE := $(CPP) $(CPPFLAGS)

stack: stack.cc Stack.h Stack_string.h
	$(COMPILE) -o $@ $^

clean:
	$(RM) -v $(BIN) *.o
