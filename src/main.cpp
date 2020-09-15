#include "../include/tetris.hpp"
using namespace std;

Shape::Shape() {
	shapetype[0] = 1;
	shapetype[1] = 2;

	trCoord[0] = 0;
	trCoord[1] = 8;

	selected = shapecoords[3];
}


void Shape::draw() {
	int currentPos[2] = { trCoord[0] + defaultPos[0], trCoord[1] + defaultPos[1]};

	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	attrset(COLOR_PAIR(2));
	for (int i = 0; i < selected.size(); ++i) {
		vector<bool> line = selected[i];
		for (int i = 0; i < 4; ++i) {
			if (line[i]) {
				mvprintw(currentPos[0], currentPos[1], string("██").c_str());
			} else{
				mvprintw(currentPos[0], currentPos[1], string("").c_str());
			}
			currentPos[1] += 2;
		}
		currentPos[0] += 1;
		currentPos[1] = trCoord[1] + defaultPos[0];
	}
	init_pair(1, COLOR_WHITE, -1);
	attrset(COLOR_PAIR(1));
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, ""); // Unicodeを出力

	// ncurses setup
	initscr();
	noecho();
	curs_set(0); // カーソル非表示
	start_color();
	use_default_colors(); // 背景色と前景色の組

	Shape shape;
	shape.draw();
	Screen screen;
	screen.draw_frame();
	
	mvprintw(12, 30, "Hello World");
	while (true) {
		int ch = getch();
		if (ch == 'q') break;
	}

	// ncurses cleanup
	endwin();
	return 0;
}
