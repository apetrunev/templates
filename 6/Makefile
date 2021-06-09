CPP = g++
CPPFLAGS = -Wall -g -O0 -std=c++17
SRC = first_example.cc perfect_forwarding.cc special_member.cc
LIBS = 
HEADERS = 
BIN = test_first test_forward test_specmember

.PHONY: all clean

all: $(BIN)

COMPILE := $(CPP) $(CPPFLAGS)

test_first: first_example.cc $(HEADERS)
	$(COMPILE) -o $@ $< 	

test_forward: perfect_forwarding.cc $(HEADERS)
	$(COMPILE) -o $@ $<

test_specmember: special_member.cc
	$(COMPILE) -o $@ $<

clean:
	$(RM) $(BIN) *.o
