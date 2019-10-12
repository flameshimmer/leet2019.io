#include "stdafx.h"
//Given a 2D binary matrix filled with 0's and 1's, find 
//the largest rectangle containing only 1's and return its area.
//
//Example:
//
//Input:
//[
//  ["1","0","1","0","0"],
//  ["1","0","1","1","1"],
//  ["1","1","1","1","1"],
//  ["1","0","0","1","0"]
//]
//Output: 6 

namespace Solution2019
{
	namespace MaximalRectangle
	{
		void GetHistograms(vector<vector<char>>& matrix, vector<vector<int>>& histograms) {
			for (int i = 0; i < matrix[0].size(); i++) {
				histograms[0][i] = (matrix[0][i] == '0' ? 0 : 1);
			}

			for (int i = 1; i < matrix.size(); i++) {
				for (int j = 0; j < matrix[0].size(); j++) {
					histograms[i][j] = matrix[i][j] == '1' ? histograms[i - 1][j] + 1 : 0;
				}
			}
		}

		int getHistogramMaxArea(vector<vector<int>>& h, int i) {
			stack<int> s;
			vector<int>& arr = h[i];
			arr.push_back(0);
			int result = 0;
			for (int i = 0; i < arr.size(); i++) {
				if (s.empty() || arr[i] >= arr[s.top()]) {
					s.push(i);
				}
				else {
					int tmp = s.top();
					s.pop();
					int startIndex = s.empty() ? -1 : s.top();
					result = max(result, arr[tmp] * (i - startIndex - 1));
					i--;
				}
			}
			return result;
		}

		int maximalRectangle(vector<vector<char>>& matrix) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return 0; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return 0; }

			vector<vector<int>> histograms(rowCount, vector<int>(colCount, 0));
			GetHistograms(matrix, histograms);

			int result = 0;
			for (int i = 0; i < rowCount; i++) {
				result = max(result, getHistogramMaxArea(histograms, i));
			}
			return result;
		}
		void Main() {
			vector<vector<char>> test = { {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
			print(maximalRectangle(test));
		}
	}
}

