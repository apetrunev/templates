CPP = g++
CPPFLAGS = -Wall -std=c++14
CPPLIBS =
BIN = stack stack_default_args

.PHONY: all clean

all: $(BIN)

COMPILE := $(CPP) $(CPPFLAGS)

stack: stack.cc Stack.h Stack_string.h Stack_default_args.h MyClass.h
	$(COMPILE) -o $@ $^

stack_default_args: stack_default_args.cc Stack_default_args.h 
	$(COMPILE) -o $@ $^

clean:
	$(RM) -v $(BIN) *.o
