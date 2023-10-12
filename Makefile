CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic
OBJECTS = main.o sokoban.o
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LIBBOOST = -lboost_unit_test_framework

all: sokoban

sokoban: $(OBJECTS)
	$(CC) $(CFLAGS) -o sokoban main.o sokoban.o $(LIB)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

sokoban.o: sokoban.cpp sokoban.hpp
	$(CC) $(CFLAGS) -c sokoban.cpp

lint:
	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir --root=. *

clean:
	rm *.o sokoban