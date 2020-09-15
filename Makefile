CC = g++
CFLAGS = -std=c++17 -Wall -lncurses

tetris: src/main.cpp src/screen.cpp
	$(CC) $(CFLAGS) -o $@ $+

.PHONY: clean
clean:
	rm -f *.o tetris
