#include "stdafx.h"
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//A sudoku solution must satisfy all of the following rules :
//
//Each of the digits 1 - 9 must occur exactly once in each row.
//Each of the digits 1 - 9 must occur exactly once in each column.
//Each of the the digits 1 - 9 must occur exactly once in each of the 9 3x3 
//sub - boxes of the grid.
//Empty cells are indicated by the character '.'.
//
//A sudoku puzzle...
//... and its solution numbers marked in red.
//
//Note:
//The given board contain only digits 1 - 9 and the character '.'.
//You may assume that the given Sudoku puzzle will have a single unique solution.
//The given board size is always 9x9.

namespace Solution2019
{
	namespace SudokuSolver
	{
		namespace Memorization {
			bool row[9][10];
			bool col[9][10];
			bool grid[3][3][10];


			bool solve(vector<vector<char>>& board, int i, int j) {
				if (i >= 9) { return true; }
				int nextRow = i + (j + 1) / 9;
				int nextCol = (j + 1) % 9;
				if (board[i][j] != '.') { return solve(board, nextRow, nextCol); }

				for (int v = 1; v <= 9; v++) {
					if (!row[i][v] && !col[j][v] && !grid[i / 3][j / 3][v]) {
						board[i][j] = '0' + v;
						row[i][v] = true;
						col[j][v] = true;
						grid[i / 3][j / 3][v] = true;
						if (solve(board, nextRow, nextCol)) { return true; }
						board[i][j] = '.';
						row[i][v] = false;
						col[j][v] = false;
						grid[i / 3][j / 3][v] = false;
					}
				}
				return false;
			}

			void solveSudoku(vector<vector<char>>& board) {
				memset(row, 0, sizeof(row));
				memset(col, 0, sizeof(row));
				memset(grid, 0, sizeof(grid));

				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						if (board[i][j] != '.') {
							int v = board[i][j] - '0';
							row[i][v] = true;
							col[j][v] = true;
							grid[i / 3][j / 3][v] = true;
						}
					}
				}
				solve(board, 0, 0);
			}
		}

		namespace LineByLine {
			bool check(vector<vector<char>>& board, int i, int j, char val) {
				for (int x = 0; x < 9; x++) { if (board[x][j] == val) { return false; } }
				for (int y = 0; y < 9; y++) { if (board[i][y] == val) { return false; } }

				int row = i - i % 3;
				int col = j - j % 3;
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (board[row + x][col + y] == val) { return false; }
					}
				}
				return true;
			}

			bool solve(vector<vector<char>>& board, int i, int j) {
				if (i == 9) { return true; }
				if (j == 9) { return solve(board, i + 1, 0); }
				if (board[i][j] != '.') { return solve(board, i, j + 1); }

				for (char c = '1'; c <= '9'; c++) {
					if (check(board, i, j, c)) {
						board[i][j] = c;
						if (solve(board, i, j + 1)) { return true; }
						board[i][j] = '.';
					}
				}
				return false;
			}

			void solveSudoku(vector<vector<char>>& board) {
				solve(board, 0, 0);
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

