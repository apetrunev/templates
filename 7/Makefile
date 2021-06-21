CPP = g++
CPPFLAGS = -Wall -g -O0 -std=c++17
LIBS =
HEADERS =
SRC = const_ref.cc like_ref.cc ret_ref.cc
BIN = test_constref test_likeref test_ret

.PHONY: all clean

all: $(BIN)

COMPILE := $(CPP) $(CPPFLAGS)

test_constref: const_ref.cc $(HEADERS)
	$(COMPILE) -o $@ $<

test_likeref: like_ref.cc $(HEADERS)
	$(COMPILE) -o $@ $<

test_ret: ret_ref.cc $(HEADERS)
	$(COMPILE) -o $@ $< 

clean:
	$(RM) *.o $(BIN)
