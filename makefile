CC = g++
COPTS = -std=c++0x

all: main

main: main.cpp
	$(CC) $(COPTS) -o main $<