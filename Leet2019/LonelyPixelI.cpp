#include "stdafx.h"
//Given a picture consisting of blackand white pixels, 
//find the number of black lonely pixels.
//
//The picture is represented by a 2D char array consisting 
//of 'B' and 'W', which means blackand white pixels respectively.
//
//A black lonely pixel is character 'B' that located at a 
//specific position where the same rowand same column 
//don't have any other black pixels.
//
//Example:
//Input:
//[['W', 'W', 'B'],
//['W', 'B', 'W'],
//['B', 'W', 'W']]
//
//Output : 3
//Explanation : All the three 'B's are black lonely pixels.
//Note :
//The range of width and height of the input 2D array is[1, 500].

namespace Solution2019
{
	namespace LonelyPixelI
	{

		int findLonelyPixel(vector<vector<char>>& picture) {
			int rowCount = picture.size();
			if (rowCount == 0) { return 0; }
			int colCount = picture[0].size();
			if (colCount == 0) { return 0; }
			
			int* row = new int[rowCount];
			int* col = new int[colCount];

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (picture[i][j] == 'B') {
						row[i]++;
						col[j]++;
					}
				}			
			}
			int result = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (picture[i][j] == 'B' && (row[i] == 1) & (col[j] == 1)) {
						result++;
					}
				}
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

