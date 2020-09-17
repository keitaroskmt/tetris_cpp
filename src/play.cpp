#include "../include/play.hpp"
using namespace std;

Play::Play(Draw &draw, int width, int height) :
draw(draw), width(width), height(height) {
	pieceSet.initRand();

	board = new int*[height];
	for (int i = 0; i < height; ++i) {
		board[i] = new int[width];
		for (int j = 0; j < width; ++j) {
			board[i][j] = 0; 
		}
	}

	current = NULL;
	next = pieceSet.getRandomPiece();
}

Play::~Play() {
	for (int i = 0; i < height; ++i) {
		delete [] board[i];
	}
	delete [] board;
}

void Play::drawBoard() const {
	clear();
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			draw.drawBlock(i, j, board[i][j]);
		}
	}
	refresh();
}

bool Play::place(int x, int y, const Piece &piece) {
	if (y + piece.getWidth() > width || isCovered(x, y, piece)) {
		return false;
	}

	posX = x;
	posY = y;

	Point apt[4];
	piece.getBody(apt);
	int color = piece.getColor();

	for (int i = 0; i < 4; ++i) {
		board[x + apt[i].x][y + apt[i].y] = color;
	}
	return true;
}

bool Play::rotate() {
	Piece *tmp = current;

	int rotation = (current->getRotation() + 1) % PieceSet::NUM_ROTATIONS;

	pieceClear(*current);
	current = pieceSet.getPiece(current->getId(), rotation);

	if (place(posX, posY, *current)) {
		return true;
	}

	current = tmp;
	place(posX, posY, *current);
	return false;
}

bool Play::move(int dx, int dy) {
	if (posX + dx < 0 || posY + dy < 0 || posY + dy + current->getWidth() > width) {
		return false;
	}
	if (dy < 0 && isHitLeft()) {
		return false;
	}
	if (dy > 0 && isHitRight()) {
		return false;
	}
	if (dx > 0 && isHitBottom()) {
		return false;
	}

	pieceClear(*current);
	return place(posX + dx, posY + dy, *current);
}

void Play::updateBoard() {
	if (current == NULL || !move(1, 0)) {
		int lines = clearRows();
		dropRandomPiece();
	}
}

void Play::pieceClear(const Piece &piece) {
	Point apt[4];
	piece.getBody(apt);
	int x, y;
	for (int i = 0; i < 4; ++i) {
		x = posX + apt[i].x;
		y = posY + apt[i].y;
		if (x >= height || y >= width) {
			continue;
		}
		board[x][y] = 0;
	}
}

void Play::dropRandomPiece() {
	current = next;
	next = pieceSet.getRandomPiece();
	place(0, 3, *current);
}

bool Play::isHitBottom() const {
	Point apt[4];
	int n = current->getBottom(apt);
	int x, y;
	for (int i = 0; i < n; ++i) {
		x = posX + apt[i].x;
		y = posY + apt[i].y;
		if (x == height - 1 || board[x+1][y] != 0) {
			return true;
		}
	}
	return false;
}

bool Play::isHitLeft() const {
	Point apt[4];
	int n = current->getLeftSide(apt);
	int x, y;
	for (int i = 0; i < n; ++i) {
		x = posX + apt[i].x;
		y = posY + apt[i].y;
		if (y == 0 || board[x][y-1] != 0) {
			return true;
		}
	}
	return false;
}

bool Play::isHitRight() const {
	Point apt[4];
	int n = current->getRightSide(apt);
	int x, y;
	for (int i = 0; i < n; ++i) {
		x = posX + apt[i].x;
		y = posY + apt[i].y;
		if (y == width - 1 || board[x][y+1] != 0) {
			return true;
		}
	}
	return false;
}

bool Play::isCovered(int x, int y, const Piece &piece) const {
	Point apt[4];
	piece.getBody(apt);
	int tmpX, tmpY;
	for (int i = 0; i < 4; ++i) {
		tmpX = apt[i].x + x;
		tmpY = apt[i].y + y;
		if (tmpX >= height || tmpY >= width) {
			continue;
		}
		if (board[tmpX][tmpY] != 0) {
			return true;
		}
	}
	return false;
}

int Play::clearRows() {
	bool isComplete;
	int rows = 0;

	for (int i = height - 1; i >= 0; --i) {
		for (int j = 0; j < width; ++j) {
			if (board[i][j] == 0) {
				isComplete  = false;
				break;
			}

			if (j == width - 1) {
				isComplete = true;
			}
		}

		if (isComplete) {
			for (int j = 0; j < width; ++j) {
				board[i][j] = 0;
			}

			for (int j = i; j > 0; --j) {
				for (int k = 0; k < width; ++k) {
					board[j][k] = board[j-1][k];
				}
			}
			i++;
			rows++;
		}
	}
	return rows;
}

bool Play::isGameOver() {
	if (current) {
		pieceClear(*current);
	}

	for (int i = 0; i < width; ++i) {
		if (board[0][i]) {
			if (current) {
				place(posX, posY, *current);
			}
			return true;
		}
	}

	if (current) {
		place(posX, posY, *current);
	}	
	return false;
}
