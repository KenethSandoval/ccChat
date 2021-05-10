CC = g++


all: main client

main: main.cpp
		 $(CC) -o main.out main.cpp

client: client.cpp
		 $(CC) -o client.out client.cpp
