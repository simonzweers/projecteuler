CC=$(shell which gcc)
CXX=$(shell which g++)

CFLAGS=-Wall -g

C_SRC=$(wildcard src/*.c)
BLD=build

C_EXE=$(C_SRC:src/%.c=$(BLD)/%)

.PHONY: all clean

all: $(C_EXE)

$(C_EXE): $(BLD)/%: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf build

