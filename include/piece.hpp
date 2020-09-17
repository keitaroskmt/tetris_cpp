#pragma once

#include <iostream>
#include <algorithm>

struct Point {
	int x;
	int y;
};

class Piece {
	public:
		Piece(int pieceId, int pieceRotation, int pieceColor, const Point *apt, int numPoints = 4);
		virtual ~Piece();

		// Getters for piece properties
		inline int getWidth() const { return width; }
		inline int getHeight() const { return height; }
		inline int getNPoints() const { return nPoints; }
		inline int getId() const { return id; }
		inline int getRotation() const { return rotation; }
		inline int getColor() const { return color; }

		// Gets the points of the piece
		void getBody(Point *apt) const;

		// Gets the bottom, left, or right part of points of the piece (Returns the number of such points)
		int getBottom(Point *apt) const;
		int getLeftSide(Point *apt) const;
		int getRightSide(Point *apt) const;

		// Determines if the piece has a point (x, y)
		// x is horizontal, and positive direction is down
		// y is vertical, and positive direction is right
		bool isPointExists(int x, int y) const;

		// for debug
		void print() const;

	protected:
		// Point array of which the piece is composed
		Point *body;

		// Piece type ID and rotation
		int id;
		int rotation;

		// Piece color
		int color;

		// Number of points in body
		int nPoints;

		int width;
		int height;
};
