#include "stdafx.h"

//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
//surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//Example:
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be:
//X X X X
//X X X X
//X X X X
//X O X X
//Explanation:
//Surrounded regions shouldn’t be on the border, which means that any 'O' on
//the border of the board are not flipped to 'X'. Any 'O' that is not on the
//border and it is not connected to an 'O' on the border will be flipped to 'X'.
//Two cells are connected if they are adjacent cells connected horizontally or
//vertically.

namespace Solution2019
{
	namespace SurroundedRegions
	{
		namespace FastOnlyProcessEdgeO {
			void check(vector<vector<char>>& board, int i, int j, int rowCount, int colCount) {
				if (i < 0 || i >= rowCount || j < 0 || j >= colCount || board[i][j] != 'O') { return; }
				board[i][j] = '1';
				check(board, i - 1, j, rowCount, colCount);
				check(board, i + 1, j, rowCount, colCount);
				check(board, i, j - 1, rowCount, colCount);
				check(board, i, j + 1, rowCount, colCount);
			}


			void solve(vector<vector<char>>& board) {
				int rowCount = board.size();
				if (rowCount == 0) { return; }
				int colCount = board[0].size();
				if (colCount == 0) { return; }

				for (int j = 0; j < colCount; j++) {
					if (board[0][j] == 'O') {
						check(board, 0, j, rowCount, colCount);
					}
				}
				if (rowCount > 1) {
					for (int j = 0; j < colCount; j++) {
						if (board[rowCount - 1][j] == 'O') {
							check(board, rowCount - 1, j, rowCount, colCount);
						}
					}
				}

				for (int i = 0; i < rowCount; i++) {
					if (board[i][0] == 'O') {
						check(board, i, 0, rowCount, colCount);
					}
				}
				if (colCount > 1) {
					for (int i = 0; i < rowCount; i++) {
						if (board[i][colCount - 1] == 'O') {
							check(board, i, colCount - 1, rowCount, colCount);
						}
					}
				}

				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						if (board[i][j] == 'O') { board[i][j] = 'X'; }
						else if (board[i][j] == '1') { board[i][j] = 'O'; }
					}
				}
			}
		}
		namespace SlowProcessEveryO {
			void flipRegion(vector<vector<char>>& board, set<pair<int, int>>& region) {
				for (auto& p : region) {
					board[p.first][p.second] = 'X';
				}
			}

			void helper(vector<vector<char>>& board, int i, int j, int rowCount, int colCount, set<pair<int, int>>& region, bool& flip) {
				if (i < 0 || i >= rowCount || j < 0 || j >= colCount || board[i][j] != 'O' || region.find({ i, j }) != region.end()) { return; }
				if (i == 0 || j == 0 || i == rowCount - 1 || j == colCount - 1) { flip = false; }
				region.insert({ i, j });

				helper(board, i - 1, j, rowCount, colCount, region, flip);
				helper(board, i + 1, j, rowCount, colCount, region, flip);
				helper(board, i, j - 1, rowCount, colCount, region, flip);
				helper(board, i, j + 1, rowCount, colCount, region, flip);
			}


			void solve(vector<vector<char>>& board) {
				int rowCount = board.size();
				if (rowCount == 0) { return; }
				int colCount = board[0].size();
				if (colCount == 0) { return; }

				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						if (board[i][j] != 'O') { continue; }
						bool flip = true;
						set<pair<int, int>> region;
						helper(board, i, j, rowCount, colCount, region, flip);
						if (flip) { flipRegion(board, region); }
					}
				}
				return;
			}
		}

		void Main() {
			vector<vector<char>> test = { {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'} };
			FastOnlyProcessEdgeO::solve(test);
		}
	}
}

