CC = g++
CFLAGS = -Wall
OBJS = Item.o Area.o Player.o Exit.o


spaceAdventure: spaceAdventure.cpp $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g -o goAdventure spaceAdventure.cpp 

classes.o: Item.o Area.o Player.o
	
Item.o: Item.cpp Item.h
	$(CC) $(CFLAGS) -g -c Item.cpp

Area.o: Area.cpp Area.h
	$(CC) $(CFLAGS) -g -c Area.cpp

Exit.o: Exit.cpp Exit.h
	g++ -g -c Exit.cpp


Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -g -c Player.cpp


.PHONY: clean
clean: 
	rm *.o
