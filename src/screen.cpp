#include "../include/tetris.hpp"
using namespace std;

Screen::Screen() {

}

void Screen::draw_frame() {
	for (int i = 1; i <= 20; ++i) {
		if (i >= 10) mvprintw(i, 0, to_string(i/10).c_str());
		mvprintw(i, 1, to_string(i%10).c_str());
		mvprintw(i, 23, "|");
	}
	for (int i = 1; i <= 10; ++i) {
		if (i >= 10) mvprintw(0, 2*i, to_string(i).c_str());
		mvprintw(0, 2*i, (" "+to_string(i)).c_str());
		mvprintw(21, 2*i, "ー");
	}

	return;
}
