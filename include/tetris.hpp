#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ncurses.h>
#include <algorithm>
using namespace std;

const int SCREEN_WIDTH = 10;
const int SCREEN_HEIGHT = 20;

class Shape {
	public:
		// constructor
		Shape(); 

		const int defaultPos[2] = {0, 0};
		int trCoord[2]; // the current top left of the shape
		
		vector<vector<bool>> selected; // the current selected shape
		vector<vector<bool>> nextup; // the next shape

		int shapetype[2];
		int color = COLOR_YELLOW;

		vector<vector<vector<bool>>> shapecoords = {
			{
				// 'O' block
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			{
				// 'I' block
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				// 'J' block
				{0,1,1,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				// 'L' block
				{0,1,1,0},
				{0,0,1,0},
				{0,0,1,0},
				{0,0,0,0}
			},
			{
				// 'Z' block
				{0,0,1,0},
				{0,1,1,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				// 'S' block
				{0,1,0,0},
				{0,1,1,0},
				{0,0,1,0},
				{0,0,0,0}
			},
			{
				// 'T' block
				{0,0,0,0,0},
				{0,0,1,0,0},
				{0,1,1,1,0},
				{0,0,0,0,0},
				{0,0,0,0,0}
			}
		};

		vector<int> colors = {COLOR_YELLOW, COLOR_CYAN, COLOR_BLUE, COLOR_WHITE, COLOR_GREEN, COLOR_MAGENTA};

		void draw();
};

class Screen {
	public:
		Screen();

		void draw_frame();
};

void play(Shape shape);
