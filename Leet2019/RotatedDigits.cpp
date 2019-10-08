#include "stdafx.h"
//X is a good number if after rotating each digit individually 
//by 180 degrees, we get a valid number that is different from X. 
//Each digit must be rotated - we cannot choose to leave it alone.
//
//A number is valid if each digit remains a digit after rotation. 
//0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 
//6 and 9 rotate to each other, and the rest of the numbers do not
//rotate to any other number and become invalid.
//
//Now given a positive number N, how many numbers X from 1 to N are good?
//
//Example:
//Input: 10
//Output: 4
//Explanation: 
//There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
//Note that 1 and 10 are not good numbers, since they remain unchanged 
//after rotating.
//
//Note:
//N  will be in range [1, 10000].
namespace Solution2019
{
	namespace RotatedDigits
	{
		bool isValid(int N) {
			bool result = false;
			while (N) {
				int remain = N % 10;
				if (remain == 2 || remain == 5 || remain == 6 || remain == 9) { result = true; }
				else if (remain == 3 || remain == 4 || remain == 7) { return false; }
				N /= 10;
			}
			return result;
		}

		int rotatedDigits(int N) {
			int result = 0;
			for (int i = 0; i <= N; i++) {
				if (isValid(i)) { result++; }
			}
			return result;
		}

		int rotatedDigitsWithDP(int N) {
			vector<int> dp(N + 1, 0);
			int result = 0;

			for (int i = 0; i <= N; i++) {
				if (i < 10) {
					if (i == 0 || i == 1 || i == 8) { dp[i] = 1; }
					else if (i == 2 || i == 5 || i == 6 || i == 9) {
						dp[i] = 2;
						result++;
					}
				}
				else {
					int a = dp[i / 10];
					int b = dp[i % 10];
					if (a == 1 && b == 1) { dp[i] = 1; }
					else if (a >= 1 && b >= 1) {
						dp[i] = 2;
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

