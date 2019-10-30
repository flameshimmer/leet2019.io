#include "stdafx.h"

//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//Example 1:
//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//Output: true
//
//Example 2:
//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//Output: false 

namespace Solution2019
{
	namespace InterleavingString
	{
		namespace OneDimensionalDp {
			bool isInterleave(string s1, string s2, string s3) {
				int len1 = s1.size();
				int len2 = s2.size();
				int len3 = s3.size();
				if (len1 + len2 != len3) { return false; }

				vector<bool> dp(len2 + 1);
				for (int j = 0; j < len2 + 1; j++) {
					dp[j] = (s2.substr(0, j) == s3.substr(0, j));
				}
				for (int i = 1; i < len1 + 1; i++) {
					dp[0] = (s1.substr(0, i) == s3.substr(0, i));
					for (int j = 1; j < len2 + 1; j++) {
						dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1])
							|| (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
					}
				}
				return dp[len2];
			}
		}

		namespace TwoDimensionalDp {
			bool isInterleave(string s1, string s2, string s3) {
				int len1 = s1.size();
				int len2 = s2.size();
				int len3 = s3.size();
				if (len3 != len1 + len2) { return false; }

				vector<vector<bool>> table(len1 + 1, vector<bool>(len2 + 1, false));
				for (int i = 0; i < len1 + 1; i++) {
					for (int j = 0; j < len2 + 1; j++) {
						if (i == 0 && j == 0) { table[i][j] = true; }
						else if (i == 0) { table[i][j] = table[i][j - 1] && s2[j - 1] == s3[i + j - 1]; }
						else if (j == 0) { table[i][j] = table[i - 1][j] && s1[i - 1] == s3[i + j - 1]; }
						else {
							table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1])
								|| (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
						}
					}
				}
				return table[len1][len2];
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

