CC=g++
BUILDDIR ?= output

TARGET := ${BUILDDIR}/knn_search
SRC := $(wildcard $src/*.c)

COMMON_FLAGS := -Wall -Wextra -Werror

.PHONY: all clean test

all:
	$(CC)  -o knn_search src/main.cpp

clean:
	$(RM) -r Trace.txt knn_search solution_path.txt

test: all
	./knn_search