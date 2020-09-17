#pragma once

#include "piece.hpp"
#include <stdio.h>
#include <ncurses.h>
#include <ctime>

class PieceSet {
	public:
		PieceSet();
		virtual ~PieceSet();

		enum { NUM_ROTATIONS = 4, NUM_PIECES = 7, NUM_POINTS = 4 };
		//const int NUM_ROTATIONS = 4;
		//const int NUM_PIECES = 7;

		Piece *getPiece(int id, int rotation = 0) const;

		inline void initRand() const { srand((unsigned int)time(NULL)); }
		inline Piece *getRandomPiece() const { return getPiece(rand() % NUM_PIECES, rand() % NUM_ROTATIONS); }

	protected:
		Piece *pieces[NUM_PIECES][NUM_ROTATIONS];

		void rotateAll();

		void rotate(Point *apt, int numPoints = 4);
};
