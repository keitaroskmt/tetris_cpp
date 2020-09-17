#include "../include/game.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char** argv) {

	Draw draw(10, 20);
	Game game(draw);

	while (true) {
		int ch = getch();
		game.keyPress(ch);

		if (ch == 'q') break;

		game.timerUpdate();


		flushinp();
		usleep(200000);
	}

	/*
	PieceSet ps;
	for (int i = 0; i < PieceSet::NUM_PIECES; ++i) {
		for (int j = 0; j < PieceSet::NUM_ROTATIONS; ++j) {
			ps.getPiece(i, j)->print();
		}
	}
	*/

	return 0;
}
