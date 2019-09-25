#include "stdafx.h"
//Given a picture consisting of black and white pixels, and a 
//positive integer N, find the number of black pixels located 
//at some specific row R and column C that align with all the 
//following rules:
//
//Row R and column C both contain exactly N black pixels.
//For all rows that have a black pixel at column C, they should
//be exactly the same as row R
//The picture is represented by a 2D char array consisting of 
//'B' and 'W', which means black and white pixels respectively.
//
//Example:
//Input:                                            
//[['W', 'B', 'W', 'B', 'B', 'W'],    
// ['W', 'B', 'W', 'B', 'B', 'W'],    
// ['W', 'B', 'W', 'B', 'B', 'W'],    
// ['W', 'W', 'B', 'W', 'B', 'W']] 
//
//N = 3
//Output: 6
//Explanation: All the bold 'B' are the black pixels 
//we need (all 'B's at column 1 and 3).
//        0    1    2    3    4    5         column index                                            
//0    [['W', 'B', 'W', 'B', 'B', 'W'],    
//1     ['W', 'B', 'W', 'B', 'B', 'W'],    
//2     ['W', 'B', 'W', 'B', 'B', 'W'],    
//3     ['W', 'W', 'B', 'W', 'B', 'W']]    
//row index
//
//Take 'B' at row R = 0 and column C = 1 as an example:
//Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
//Rule 2, the rows have black pixel at column C = 1 are row 0, 
//row 1 and row 2. They are exactly the same as row R = 0.
//
//Note:
//The range of width and height of the input 2D array is [1,200].

namespace Solution2019
{
	int findBlackPixel(vector<vector<char>>& picture, int N) {
		int rowCount = picture.size();
		if (rowCount == 0) { return 0; }
		int colCount = picture[0].size();
		if (colCount == 0) { return 0; }

		unordered_map<int, set<int>> row;
		unordered_map<int, set<int>> col;

		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				if (picture[i][j] == 'B') {
					row[i].insert(j);
					col[j].insert(i);
				}
			}
		}

		int result = 0;
		for (auto& r1 : row) {
			for (int j : r1.second) {
				int i = r1.first;
				if (row[i].size() != N || col[j].size() != N) { continue; }
				bool same = true;
				for (int r : col[j]) {
					if (row[r] != row[i]) { same = false; break; }
				}
				if (same) { result++; }
			}
		}
		return result;
	}
	namespace LonelyPixelII
	{
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

