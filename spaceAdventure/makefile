
spaceAdventure: spaceAdventure.cpp classes.o
	g++ -g -o goAdventure spaceAdventure.cpp

classes.o: Item.o Area.o Player.o
	
Item.o: Item.cpp Item.h
	g++ -g -c Item.cpp

Area.o: Area.cpp Area.h
	g++ -g -c Area.cpp

#Exit.o: Exit.cpp Exit.h
#	g++ -g -c Exit.cpp


Player.o: Player.cpp Player.h
	g++ -g -c Player.cpp


.PHONY: clean
clean: 
	rm *.o
