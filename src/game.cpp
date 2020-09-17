#include "../include/game.hpp"
using namespace std;

Game::Game(Draw &draw) :
draw(draw) {
	play = new Play(draw, 10, 20);
}

Game::~Game() {
	delete play;
}

void Game::restart() {
	delete play;
	play = new Play(draw, 10, 20);
	repaint();
}

bool Game::keyPress(int ch) {
	switch (ch) {
		case KEY_UP:
			play->rotate();
			break;
		case KEY_DOWN:
			play->move(1, 0);
			break;
		case KEY_LEFT:
			play->move(0, -1);
			break;
		case KEY_RIGHT:
			play->move(0, 1);
			break;
		default:
			return false;
	}
	return true;
}

void Game::timerUpdate() {
	if (play->isGameOver()) {
		drawGameOver();
		return;
	}

	play->updateBoard();

	play->drawBoard();
}


void Game::repaint() const {
	draw.drawFrame();
	play->drawBoard();

	if (play->isGameOver()) {
		return;
	}
}

bool Game::isGameOver() const {
	return play->isGameOver();
}
