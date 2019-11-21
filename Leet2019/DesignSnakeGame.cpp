#include "stdafx.h"

//Design a Snake game that is played on a device with screen size = width x
//height. Play the game online if you are not familiar with the game.
//The snake is initially positioned at the top left corner (0,0) with length = 1
//unit.
//You are given a list of food's positions in row-column order. When a snake eats
//the food, its length and the game's score both increase by 1.
//Each food appears one by one on the screen. For example, the second food will
//not appear until the first food was eaten by the snake.
//When a food does appear on the screen, it is guaranteed that it will not appear
//on a block occupied by the snake.
//
//Example:
//Given width = 3, height = 2, and food = [[1,2],[0,1]].
//Snake snake = new Snake(width, height, food);
//Initially the snake appears at position (0,0) and the food at (1,2).
//|S| | |
//| | |F|
//snake.move("R"); -> Returns 0
//| |S| |
//| | |F|
//snake.move("D"); -> Returns 0
//| | | |
//| |S|F|
//snake.move("R"); -> Returns 1 (Snake eats the first food and right after that,
//the second food appears at (0,1) )
//| |F| |
//| |S|S|
//snake.move("U"); -> Returns 1
//| |F|S|
//| | |S|
//snake.move("L"); -> Returns 2 (Snake eats the second food)
//| |S|S|
//| | |S|
//snake.move("U"); -> Returns -1 (Game over because snake collides with border)

namespace Solution2019
{
	namespace DesignSnakeGame
	{
		class SnakeGame {
			int rowCount;
			int colCount;
			int pos;
			vector<vector<int>> food;
			deque<pair<int, int>> body;
		public:
			/** Initialize your data structure here.
				@param width - screen width
				@param height - screen height
				@param food - A list of food positions
				E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
			SnakeGame(int width, int height, vector<vector<int>>& food) {
				rowCount = height;
				colCount = width;
				this->food = food;
				pos = 0;
				body.push_front({ 0, 0 });
			}

			/** Moves the snake.
				@param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
				@return The game's score after the move. Return -1 if game over.
				Game over when snake crosses the screen boundary or bites its body. */
			int move(string direction) {
				int r = body.front().first;
				int c = body.front().second;
				if (direction == "U") { r--; }
				else if (direction == "D") { r++; }
				else if (direction == "L") { c--; }
				else if (direction == "R") { c++; }

				if (r < 0 || r >= rowCount || c < 0 || c >= colCount) { return -1; }
				pair<int, int> tmp = { r, c };
				if (find(body.begin(), body.end(), tmp) != body.end() && tmp != body.back()) { return -1; }

				body.push_front({ r, c });

				if (pos < food.size() && food[pos][0] == r && food[pos][1] == c) {
					pos++;
				}
				else { body.pop_back(); }

				return pos;
			}
		};

		/**
		 * Your SnakeGame object will be instantiated and called as such:
		 * SnakeGame* obj = new SnakeGame(width, height, food);
		 * int param_1 = obj->move(direction);
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

