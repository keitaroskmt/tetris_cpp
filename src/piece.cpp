#include "../include/piece.hpp"
using namespace std;

Piece::Piece(int pieceId, int pieceRotation, int pieceColor, const Point *apt, int numPoints) :
id(pieceId), rotation(pieceRotation), color(pieceColor), nPoints(numPoints), width(0), height(0) {
	Point topLeft = apt[0];

	for (int i = 1; i < nPoints; ++i) {
		topLeft.x = min(topLeft.x, apt[i].x);
		topLeft.y = min(topLeft.y, apt[i].y);
	}

	body = new Point[nPoints];

	for	(int i = 0; i < nPoints; ++i) {
		body[i].x = apt[i].x - topLeft.x;
		body[i].y = apt[i].y - topLeft.y;
		
		height = max(height, body[i].x + 1);
		width = max(width, body[i].y + 1);
	}
}

Piece::~Piece() {
	if (body) {
		delete [] body;
	}
}

void Piece::getBody(Point *apt) const {
	for (int i = 0; i < nPoints; ++i) {
		apt[i] = body[i];
	}
}

int Piece::getBottom(Point *apt) const {
	int i = 0;
	for (int y = 0; y < width; ++y) {
		for (int x = height - 1; x >= 0; --x) {
			if (isPointExists(x, y)) {
				apt[i].x = x;
				apt[i].y = y;
				i++;
				break;
			}
		}
	}
	return i;
}

int Piece::getLeftSide(Point *apt) const {
	int i = 0;
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			if (isPointExists(x, y)) {
				apt[i].x = x;
				apt[i].y = y;
				i++;
				break;
			}
		}
	}
	return i;
}

int Piece::getRightSide(Point *apt) const {
	int i = 0;
	for (int x = 0; x < height; ++x) {
		for (int y = width - 1; y >= 0; --y) {
			if (isPointExists(x, y)) {
				apt[i].x = x;
				apt[i].y = y;
				i++;
				break;
			}
		}
	}
	return i;
}

bool Piece::isPointExists(int x, int y) const {
	for (int i = 0; i < nPoints; ++i) {
		if (body[i].x == x && body[i].y == y) {
			return true;
		}
	}
	return false;
}

void Piece::print() const {
	cout << "id  = " << id << endl;
    cout << "rot = " << rotation << endl;
	cout << "wid = " << width << endl;
	cout << "hei = " << height << endl;
	cout << "col = " << color << endl;
	cout << "print " << endl;
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			if (isPointExists(x, y)) {
				cout << "#";
			} else {
				cout << " ";
			}
		}
		cout << endl;
	}

	Point apt[4];
	cout << "getBottom" << endl;
	int n = getBottom(apt);
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			bool flag = true;
			for (int i = 0; i < n; ++i) {
				if (apt[i].x == x && apt[i].y == y) {
					cout << "#";
					flag = false;
				}
			}
			if (flag) cout << " ";
		}
		cout << endl;
	}

	cout << "getLeft" << endl;
	n = getLeftSide(apt);
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			bool flag = true;
			for (int i = 0; i < n; ++i) {
				if (apt[i].x == x && apt[i].y == y) {
					cout << "#";
					flag = false;
				}
			}
			if (flag) cout << " ";
		}
		cout << endl;
	}

	cout << "getRight" << endl;
	n = getRightSide(apt);
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < width; ++y) {
			bool flag = true;
			for (int i = 0; i < n; ++i) {
				if (apt[i].x == x && apt[i].y == y) {
					cout << "#";
					flag = false;
				}
			}
			if (flag) cout << " ";
		}
		cout << endl;
	}
}
