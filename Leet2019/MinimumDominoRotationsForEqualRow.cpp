#include "stdafx.h"
//In a row of dominoes, A[i] and B[i] represent the top and bottom halves 
//of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - 
//	one on each half of the tile.)
//
//We may rotate the i-th domino, so that A[i] and B[i] swap values.
//
//Return the minimum number of rotations so that all the values in A are 
//the same, or all the values in B are the same.
//
//If it cannot be done, return -1.
//
//Example 1:
//Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
//Output: 2
//Explanation: 
//The first figure represents the dominoes as given by A and B: before we
//do any rotations.
//If we rotate the second and fourth dominoes, we can make every value in
//the top row equal to 2, as indicated by the second figure.
//
//Example 2:
//Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
//Output: -1
//Explanation: 
//In this case, it is not possible to rotate the dominoes to make one row
//of values equal.
//
//Note:
//1 <= A[i], B[i] <= 6
//2 <= A.length == B.length <= 20000
namespace Solution2019
{
	namespace MinimumDominoRotationsForEqualRow
	{
		int check(int target, int len, vector<int>& A, vector<int>& B) {
			int a = 0;
			int b = 0;
			for (int i = 0; i < len; i++) {
				if (A[i] != target && B[i] != target) { return -1; }
				if (A[i] != target) { a++; }
				if (B[i] != target) { b++; }
			}
			return min(a, b);
		}

		int minDominoRotations(vector<int>& A, vector<int>& B) {
			int len = A.size();
			int result = check(A[0], len, A, B);
			if (result != -1) { return result; }

			return check(B[0], len, A, B);
		}

		int minDominoRotationsAnotherWay(vector<int>& A, vector<int>& B) {
			int target1 = A[0];
			int A1 = 0;
			int B1 = 0;
			int target2 = B[0];
			int A2 = 0;
			int B2 = 0;

			int len = A.size();
			for (int i = 0; i < len; i++) {
				if (A[i] != target1 && B[i] != target1) { target1 = 0; }
				if (A[i] != target2 && B[i] != target2) { target2 = 0; }

				if (A[i] == target1) { A1++; }
				if (B[i] == target1) { B1++; }
				if (A[i] == target2) { A2++; }
				if (B[i] == target2) { B2++; }
			}
			if (target1 == 0 && target2 == 0) { return -1; }
			return min(len - max(A1, B1), len - max(A2, B2));
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

