CC=g++
BUILDDIR ?= output

TARGET := ${BUILDDIR}/knn_search
SRC := $(wildcard $src/*.c)

COMMON_FLAGS := -std=c++11 -Wall -Wextra -Werror -O4

.PHONY: all clean test

all:
	$(CC) $(COMMON_FLAGS) -o nn_search src/main.cpp src/data.cpp src/nn.cpp

clean:
	$(RM) -r Trace.txt nn_search solution_path.txt

test: all
	./nn_search
