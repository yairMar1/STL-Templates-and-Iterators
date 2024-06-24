CC = g++
CFLAGS = -std=c++17 -Wall
CXXFLAGS=-std=c++17 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

run: main
	./$^

main: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp tree.hpp node.hpp
	$(CC) $(CFLAGS) -c $<

valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all ./main

clean:
	rm -f *.o main