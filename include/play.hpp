#include "pieceSet.hpp"
#include "draw.hpp"

class Play {
	public:
		Play(Draw &draw, int width = 10, int height = 20);
		virtual ~Play();

		void drawBoard() const;

		// Rotates the droppint piece, retruns true if successfull
		bool rotate();

		// dx is vertical movement, positive value is down (normally it's positive)
		// dy is horizontal movement, positive value is right
		bool move(int dx, int dy);

		void updateBoard();

		bool isGameOver();

	protected:
		// if there isn't enough space, does nothing and returns false
		bool place(int x, int y, const Piece &piece);

		void pieceClear(const Piece &piece);

		void dropRandomPiece();

		bool isHitBottom() const;
		bool isHitLeft() const;
		bool isHitRight() const;

		bool isCovered(int x, int y, const Piece &piece) const;

		// clears full rows, and returns the number of rows being cleared
		int clearRows();

		int **board; // the drawing board (each element in the array represents a color)
		Draw &draw;
		PieceSet pieceSet; // piece generator
		Piece *current;
		Piece *next;
		int width;
		int height;
		int posX; // current location of the droppint piece
		int posY; 
		int speed; // every _spped_ millisec
};
