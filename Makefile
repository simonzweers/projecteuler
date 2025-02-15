CC=$(shell which gcc)
CXX=$(shell which g++)

CFLAGS=-Wall -O3

C_SRC=$(wildcard c/*.c)
CPP_SRC=$(wildcard cpp/*.cpp)
C_BLD=c/build
CPP_BLD=cpp/build

C_EXE=$(C_SRC:c/%.c=$(C_BLD)/%)
CPP_EXE=$(CPP_SRC:cpp/%.cpp=$(CPP_BLD)/%)
.PHONY: all clean

all: $(C_EXE) $(CPP_EXE)
	@echo "$^ | $@"
	@echo "${C_SRC}"
	@echo "${CPP_SRC}"
	@echo ""

$(C_EXE): $(C_BLD)/%: c/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

$(CPP_EXE): $(CPP_BLD)/%: cpp/%.cpp
	@echo "$^ | $@"
	mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) $^ -o $@

clean:
	rm -rf c/build cpp/build

