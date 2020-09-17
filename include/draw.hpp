#pragma once
#include "pieceSet.hpp"
#include <iostream>
#include <string>

class Draw {
	public:
		Draw(int width = 10, int height = 20);
		virtual ~Draw();

		// fills a cell
		void drawBlock(int x, int y, int color);

		void drawFrame();

		void drawText(int x, int y, const char* s);

	protected:
		int topLeft_x;
		int topLeft_y;
		int width;
		int height;
};
