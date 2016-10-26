CC = g++
CFLAGS = -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -std=c++11

all: main

main: rhombus.o trapeze.o pentagon.o main.o
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf *.o

cleanall:
	rm -rf main *.o 
