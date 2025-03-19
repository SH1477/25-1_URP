########################################################
# Makefile: I/D Cache and CPU makefile
########################################################
# 
# Author: Sehoon Kim
# Date:   2025-03-10
########################################################

CC = g++

SRC = test.cpp
EXEC = test

all: run_test

build_test:
	$(CC) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC)

run_test: build_test
