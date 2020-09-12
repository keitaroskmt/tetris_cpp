#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

class Shape {
	public:
		// constructor
		Shape(); 

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
				// 'L' block
				{0,1,1,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				// 'J' block
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
}

