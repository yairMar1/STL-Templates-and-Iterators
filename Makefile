CC = g++
CFLAGS = -std=c++17 -Wall
CXXFLAGS=-std=c++17 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

run: main
	./$^

main: main.o Complex.o
	$(CC) $(CFLAGS) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp tree.hpp node.hpp
	$(CC) $(CFLAGS) -c $<

Complex.o: Complex.cpp Complex.hpp
	$(CC) $(CFLAGS) -c $<

valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all -s ./main

clean:
	rm -f *.o main