CC = g++
COPTS = -std=c++0x

all: main

main: main.cpp question.o
	$(CC) $(COPTS) -o main $^

question.o: question.cpp question.h
	$(CC) $(COPTS) -c -o $@ $<