CC = g++
CFLAGS = -std=c++17 -Wall -lncurses

tetris: src/main.cpp src/game.cpp src/play.cpp src/draw.cpp src/pieceSet.cpp src/piece.cpp
	$(CC) $(CFLAGS) -o $@ $+

.PHONY: clean
clean:
	rm -f *.o tetris
