play:	main.o board.o game.o interface.o
		g++ -Wall main.cpp board.cpp game.cpp interface.cpp -o play

main.o:	main.cpp interface.h
		g++ -c -Wall main.cpp

board.o:	board.cpp board.h
	g++ -c -Wall board.cpp

game.o:	game.cpp game.h
		g++ -c -Wall game.cpp

interface.o: interface.cpp interface.h
	g++ -c -Wall interface.cpp

clean:
	-rm *.o play