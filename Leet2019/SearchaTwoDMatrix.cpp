#include "stdafx.h"
//Write an efficient algorithm that searches for a value 
//in an m x n matrix. This matrix has the following properties:
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last 
//integer of the previous row.
//
//Example 1:
//Input:
//matrix = [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//target = 3
//Output: true
//
//Example 2:
//Input:
//matrix = [
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//target = 13
//Output: false

namespace Solution2019
{
	namespace SearchaTwoDMatrix
	{
		// Treat the whole matrix like a 1 dimensional sorted array
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return false; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return false; }

			int start = 0;
			int end = rowCount * colCount - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				int midVal = matrix[mid / colCount][mid % colCount];
				if (midVal == target) { return true; }
				else if (midVal < target) { start = mid + 1; }
				else { end = mid - 1; }
			}
			return false;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

