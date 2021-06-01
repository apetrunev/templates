CPP = g++
CPPFLAGS = -Wall -g -std=c++17 -O0
LIBS = 
SRC = variadic-1.cc variadic-2.cc variadic-sizeof.cc fold-expressions.cc
HEADERS = 
BIN = v1 v2 v3 v4

.PHONY: all clean

all: $(BIN)

COMPILE = $(CPP) $(CPPFLAGS)

v1: variadic-1.cc $(HEADERS)
	$(COMPILE) -o $@ $< $(LIBS)

v2: variadic-2.cc $(HEADERS)
	$(COMPILE) -o $@ $< $(LIBS)

v3: variadic-sizeof.cc $(HEADERS)
	$(COMPILE) -o $@ $< $(LIBS)

v4: fold-expressions.cc $(HEADERS)
	$(COMPILE) -o $@ $< $(LIBS)

clean:
	$(RM) $(BIN)
