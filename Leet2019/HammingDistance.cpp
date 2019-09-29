#include "stdafx.h"
//The Hamming distance between two integers is the number of 
//positions at which the corresponding bits are different.
//
//Given two integers x and y, calculate the Hamming distance.
//
//Note:
//0 ≤ x, y < 231.
//
//Example:
//
//Input: x = 1, y = 4
//
//Output: 2
//
//Explanation:
//1   (0 0 0 1)
//4   (0 1 0 0)
//       ↑   ↑
//
//The above arrows point to positions where the corresponding bits are different.

namespace Solution2019
{
	namespace HammingDistance
	{
		int hammingDistance(int x, int y) {
			int z = x ^ y;
			int result = 0;
			while (z) {
			    result++; 
				z &= z - 1;
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

