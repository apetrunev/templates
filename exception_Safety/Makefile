CC := g++
CPPFLAGS := -std=c++14 -Wall 
SRC := main.cc

.PHONY: clean all

all: stack

stack: $(SRC)
	$(CC) $(CPPFLAGS) -o $@ main.cc

clean:
	$(RM) stack *.o
