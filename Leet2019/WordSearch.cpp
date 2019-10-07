#include "stdafx.h"
//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially 
//adjacent cell, where "adjacent" cells are those horizontally
//or vertically neighboring. The same letter cell may not be 
//used more than once.
//
//Example:
//
//board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//Given word = "ABCCED", return true.
//Given word = "SEE", return true.
//Given word = "ABCB", return false.

namespace Solution2019
{
	namespace WordSearch
	{
		bool helper(vector<vector<char>>& board, int rowCount, int colCount, int row, int col, string& word, int i, int len, vector<vector<bool>>& used) {
			if (i == len) { return true; }
			if (row < 0 || row >= rowCount || col < 0 || col >= colCount || used[row][col] || board[row][col] != word[i]) { return false; }

			// To save space, can also store the value of cur char, change board[row][col] to '*'
			// Then restore the board[row][col] to the stored value after the recursive call. 
			used[row][col] = true;
			bool result = helper(board, rowCount, colCount, row + 1, col, word, i + 1, len, used) ||
				helper(board, rowCount, colCount, row - 1, col, word, i + 1, len, used) ||
				helper(board, rowCount, colCount, row, col + 1, word, i + 1, len, used) ||
				helper(board, rowCount, colCount, row, col - 1, word, i + 1, len, used);
			used[row][col] = false;
			return result;
		}

		bool exist(vector<vector<char>>& board, string word) {
			int rowCount = board.size();
			if (rowCount == 0) { return false; }
			int colCount = board[0].size();
			if (colCount == 0) { return false; }
			int len = word.size();
			if (len == 0) { return true; }

			vector<vector<bool>> used(rowCount, vector<bool>(colCount, false));
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (helper(board, rowCount, colCount, i, j, word, 0, len, used)) { return true; }
				}
			}
			return false;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

