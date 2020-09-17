#include "../include/pieceSet.hpp"

PieceSet::PieceSet() {
	for (int i = 0; i < NUM_PIECES; ++i) {
		for (int j = 0; j < NUM_ROTATIONS; ++j) {
			pieces[i][j] = NULL;
		}
	}

	Point apt[NUM_POINTS];

	// 0, I piece, cyan
	apt[0].x = 0; apt[0].y = 0;
	apt[1].x = 0; apt[1].y = 1;
	apt[2].x = 0; apt[2].y = 2;
	apt[3].x = 0; apt[3].y = 3;
	pieces[0][0] = new Piece(0, 0, COLOR_CYAN, apt);

	// 1, L piece, white
	apt[0].x = 1; apt[0].y = 0;
	apt[1].x = 1; apt[1].y = 1;
	apt[2].x = 1; apt[2].y = 2;
	apt[3].x = 0; apt[3].y = 2;
	pieces[1][0] = new Piece(1, 0, COLOR_WHITE, apt);

	// 2, J piece, blue 
	apt[0].x = 0; apt[0].y = 0;
	apt[1].x = 1; apt[1].y = 0;
	apt[2].x = 1; apt[2].y = 1;
	apt[3].x = 1; apt[3].y = 2;
	pieces[2][0] = new Piece(2, 0, COLOR_BLUE, apt);

	// 3, S piece, green
	apt[0].x = 1; apt[0].y = 0;
	apt[1].x = 1; apt[1].y = 1;
	apt[2].x = 0; apt[2].y = 1;
	apt[3].x = 0; apt[3].y = 2;
	pieces[3][0] = new Piece(3, 0, COLOR_GREEN, apt);

	// 4, Z piece, red
	apt[0].x = 0; apt[0].y = 0;
	apt[1].x = 0; apt[1].y = 1;
	apt[2].x = 1; apt[2].y = 1;
	apt[3].x = 1; apt[3].y = 2;
	pieces[4][0] = new Piece(4, 0, COLOR_RED, apt);

	// 5, O piece, yellow
	apt[0].x = 0; apt[0].y = 0;
	apt[1].x = 1; apt[1].y = 0;
	apt[2].x = 0; apt[2].y = 1;
	apt[3].x = 1; apt[3].y = 1;
	pieces[5][0] = new Piece(5, 0, COLOR_YELLOW, apt);

	// 6, T piece, magenta
	apt[0].x = 0; apt[0].y = 1;
	apt[1].x = 1; apt[1].y = 0;
	apt[2].x = 1; apt[2].y = 1;
	apt[3].x = 1; apt[3].y = 2;
	pieces[6][0] = new Piece(6, 0, COLOR_MAGENTA, apt);

	rotateAll();
}

PieceSet::~PieceSet() {
	for (int i = 0; i < NUM_PIECES; ++i) {
		for (int j = 0; j < NUM_ROTATIONS; ++j) {
			if (pieces[i][j] != NULL) {
				delete pieces[i][j];
			}
		}
	}
}

Piece *PieceSet::getPiece(int id, int rotation) const {
	if (id < 0 || id >= NUM_PIECES || rotation < 0 || rotation >= NUM_ROTATIONS) {
		return NULL;
	}
	return pieces[id][rotation];
}

void PieceSet::rotateAll() {
	Point apt[NUM_POINTS];

	for (int i = 0; i < NUM_PIECES; ++i) {
		pieces[i][0]->getBody(apt);

		for (int j = 0; j < NUM_ROTATIONS; ++j) {
			rotate(apt);
			if (pieces[i][j] != NULL) {
				delete pieces[i][j];
			}
			pieces[i][j] = new Piece(i, j, pieces[i][0]->getColor(), apt);
		}
	}
}

void PieceSet::rotate(Point *apt, int numPoints) {
	int tmp;

	// counter-clockwise rotation
	// X' = -Y
	// Y' = X
	for (int i = 0; i < numPoints; ++i) {
		tmp = apt[i].x;
		apt[i].x = -apt[i].y;
		apt[i].y = tmp;
	}
}
