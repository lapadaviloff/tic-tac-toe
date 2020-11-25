game:game.o classboard.o classview.o
	g++ game.o classboard.o classview.o -o game
game.o:game.cpp classboard.h classview.h
	g++ -c game.cpp
classboard.o:classboard.cpp classboard.h
	g++ -c classboard.cpp
classview.o:classview.cpp classview.h
	g++ -c classview.cpp
clean:
	rm -rf *.o 


