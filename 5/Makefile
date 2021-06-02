CPP = g++
CPPFLAGS = -Wall -g -std=c++17
LIBS = 
SRC = zero_init.cc this_arrow.cc
HEADERS =
BIN = test test_this

.PHONY: all clean

COMPILE = $(CPP) $(CPPFLAGS)

all: $(BIN)

test: zero_init.cc $(HEADERS)
	$(COMPILE) -o $@ $< 

test_this: this_arrow.cc $(HEADERS)
	$(COMPILE) -o $@ $<

clean:
	$(RM) *.o $(BIN)


