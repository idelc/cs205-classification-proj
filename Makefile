CC=g++
BUILDDIR ?= output

TARGET := ${BUILDDIR}/knn_search
SRC := $(wildcard $src/*.c)

COMMON_FLAGS := -Wall -Wextra -Werror

.PHONY: all clean test

all:
	$(CC)  -o nn_search src/main.cpp src/data.cpp src/nn.cpp

clean:
	$(RM) -r Trace.txt nn_search solution_path.txt

test: all
	./nn_search
