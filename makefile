# edit this makefile so that running make compiles your enigma program

all: enigma

enigma: Main.o
	g++ -o enigma Main.o

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
