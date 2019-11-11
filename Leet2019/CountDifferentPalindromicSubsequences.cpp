#include "stdafx.h"

//Given a string S, find the number of different non-empty palindromic
//subsequences in S, and return that number modulo 10^9 + 7.
//A subsequence of a string S is obtained by deleting 0 or more characters from
//S.
//A sequence is palindromic if it is equal to the sequence reversed.
//Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i
//for which A_i != B_i.
//
//Example 1:
//Input: 
//S = 'bccb'
//Output: 6
//Explanation: 
//The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc',
//'bcb', 'bccb'.
//
//Note that 'bcb' is counted only once, even though it occurs twice.
//
//Example 2:
//Input: 
//S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
//Output: 104860361
//Explanation: 
//There are 3104860382 different non-empty palindromic subsequences, which is
//104860361 modulo 10^9 + 7.
//
//Note:
//The length of S will be in the range [1, 1000].
//Each character S[i] will be in the set {'a', 'b', 'c', 'd'}. 

namespace Solution2019
{
	namespace CountDifferentPalindromicSubsequences
	{
		namespace Recursion {
			vector<int> m;
			static constexpr long long kMod = 1e9 + 7;

			long long count(const string& S, int s, int e) {
				if (s > e) { return 0; }
				if (s == e) { return 1; }
				const int key = s * S.size() + e;
				if (m[key] > 0) { return m[key]; }

				long long result = 0;
				if (S[s] == S[e]) {
					int l = s + 1;
					int r = e - 1;
					while (l <= r && S[l] != S[s]) { l++; }
					while (l <= r && S[r] != S[e]) { r--; }
					if (l > r) { result = count(S, s + 1, e - 1) * 2 + 2; }
					else if (l == r) { result = count(S, s + 1, e - 1) * 2 + 1; }
					else { result = count(S, s + 1, e - 1) * 2 - count(S, l + 1, r - 1); }
				}
				else {
					result = count(S, s, e - 1) + count(S, s + 1, e) - count(S, s + 1, e - 1);
				}
				m[key] = (result + kMod) % kMod;
				return m[key];
			}

			int countPalindromicSubsequences(string S) {
				const int len = S.size();
				m = vector<int>(len * (len + 1) + 1, 0);
				return count(S, 0, len - 1);
			}
		}


		namespace DP {
			int countPalindromicSubsequences(string S) {
				int len = S.size();
				vector<vector<int>> dp(len, vector<int>(len, 0));
				for (int i = 0; i < len; i++) {
					dp[i][i] = 1;
				}

				const long long kMod = 1e9 + 7;
				for (int l = 1; l <= len; l++) {
					for (int i = 0; i < len - l; i++) {
						const int j = i + l;
						if (S[i] == S[j]) {
							dp[i][j] = dp[i + 1][j - 1] * 2;
							int l = i + 1;
							int r = j - 1;
							while (l <= r && S[l] != S[i]) { l++; }
							while (l <= r && S[r] != S[i]) { r--; }
							if (l > r) { dp[i][j] += 2; }
							else if (l == r) { dp[i][j] += 1; }
							else { dp[i][j] -= dp[l + 1][r - 1]; }
						}
						else {
							dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
						}
						dp[i][j] = (dp[i][j] + kMod) % kMod;
					}
				}
				return dp[0][len - 1];
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

