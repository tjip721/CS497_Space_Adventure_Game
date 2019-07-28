CC = g++ -std=c++11
CFLAGS = -Wall
OBJS = Item.o Area.o Player.o Exit.o Pickaxe.o parser.o Flashlight.o Mushroom.o PowerCrystal.o Spaceship.o
#include "Pickaxe.h"
#include "Flashlight.h"
#include "Mushroom.h"
#include "PowerCrystal.h"
#include "Spaceship.h"


spaceAdventure: spaceAdventure.cpp $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g -o goAdventure spaceAdventure.cpp

classes.o: Item.o Area.o Player.o Exit.o parser.o

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -g -c $< -o $@

.PHONY: clean
clean:
	rm *.o
