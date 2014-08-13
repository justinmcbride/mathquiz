CC = g++
COPTS = -std=c++0x
FINALEXEC=game

all: main

main: main.cpp question.o
	$(CC) $(COPTS) -o $(FINALEXEC) $^

question.o: question.cpp question.h
	$(CC) $(COPTS) -c -o $@ $<