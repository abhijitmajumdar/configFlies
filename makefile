CC=g++
INCLUDE = -I/usr/local/include
CFLAGS = -std=c++11 -pipe -O2 -Wall -W $(INCLUDE)

all: mainExecutable

mainExecutable: main.o configLoader.o
	$(CC) -o mainExecutable.out main.o configLoader.o

main.o: main.cpp
	$(CC) -c -o main.o main.cpp $(CFLAGS)
	
configLoader.o: configLoader.cpp
	$(CC) -c -o configLoader.o configLoader.cpp $(CFLAGS)
	
clean:
	rm main.o configLoader.o mainExecutable.out
