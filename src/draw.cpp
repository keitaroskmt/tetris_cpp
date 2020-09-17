#include "../include/draw.hpp"
using namespace std;

Draw::Draw(int width, int height) :
topLeft_x(1), topLeft_y(1), width(width), height(height) {
	setlocale(LC_ALL, ""); // Unicodeを出力

	// ncurses setup
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0); // カーソル非表示
	start_color();
	use_default_colors(); // 背景色と前景色の組
}

Draw::~Draw() {
	// ncurses cleanup
	endwin();
}

void Draw::drawBlock(int x, int y, int color) {
	int tmpX = topLeft_x + x;
	int tmpY = topLeft_y + 2 * y;
	//int tmpY = topLeft_y + y;
	
	//mvprintw(tmpX, tmpY, to_string(color).c_str());
	if (color > 0) {
		init_pair(color + 1, color, -1);
		attrset(COLOR_PAIR(color + 1));
		
		mvprintw(tmpX, tmpY, string("██").c_str());

		attrset(0);
	}
}

void Draw::drawFrame() {
	for (int i = 1; i <= height; ++i) {
		if (i >= 10) mvprintw(i, 0, to_string(i/10).c_str());
			mvprintw(i, 1, to_string(i%10).c_str());
			mvprintw(i, 23, "|");
		}
	for (int i = 1; i <= width; ++i) {
		if (i >= 10) mvprintw(0, 2*i, to_string(i).c_str());
			mvprintw(0, 2*i, (" "+to_string(i)).c_str());
			mvprintw(21, 2*i, "ー");
	}
}

void Draw::drawText(int x, int y, const char* s) {
	int tmpX = topLeft_x + x;
	int tmpY = topLeft_y + 2 * y;

	mvprintw(tmpX, tmpY, s);
}
