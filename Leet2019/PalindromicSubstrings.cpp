#include "stdafx.h"

//Given an array nums, there is a sliding window of size k which is moving from
//the very left of the array to the very right. You can only see the k numbers in
//the window. Each time the sliding window moves right by one position. Return
//the max sliding window.
//
//Example:
//Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
//Output: [3,3,5,5,6,7] 
//Explanation: 
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
//array.
//Follow up:
//Could you solve it in linear time?

namespace Solution2019
{
	namespace PalindromicSubstrings
	{
		namespace ScanEveryPosition {
			void checkPalindrome(string& s, int len, int i, int j, int& result) {
				while (i >= 0 && j < len && s[i] == s[j]) {
					result++;
					i--;
					j++;
				}
			}

			int countSubstrings(string s) {
				int len = s.size();
				if (len < 2) { return len; }

				int result = 0;
				for (int i = 0; i < len; i++) {
					checkPalindrome(s, len, i, i, result);
					checkPalindrome(s, len, i, i + 1, result);
				}
				return result;
			}
		}

		namespace DP {
			int countSubstrings(string s) {
				int len = s.size();
				int result = 0;
				vector<vector<bool>> dp(len, vector<bool>(len, false));
				for (int i = len - 1; i >= 0; i--) {
					for (int j = i; j < len; j++) {
						dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
						if (dp[i][j]) { result++; }
					}
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

