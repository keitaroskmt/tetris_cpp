#pragma once
#include "play.hpp"
#include "pieceSet.hpp"

class Game {
	public:
		Game(Draw &draw);
		virtual ~Game();

		// restarts the game
		void restart();

		// handles playe's key press
		bool keyPress(int ch);

		void timerUpdate();

		void repaint() const;

		bool isGameOver() const;

	protected:
		inline void drawGameOver() const {
			draw.drawText(5, 2, "GAME OVER");
		}

		Play *play;
		Draw &draw;
};
