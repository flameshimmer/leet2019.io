#include "stdafx.h"
//Given a string S and a string T, find the minimum 
//window in S which will contain all the characters
//in T in complexity O(n).
//
//Example:
//Input: S = "ADOBECODEBANC", T = "ABC"
//Output: "BANC"
//
//Note:
//If there is no such window in S that covers all 
//characters in T, return the empty string "".
//If there is such window, you are guaranteed that 
//there will always be only one unique minimum window in S.


namespace Solution2019
{
	namespace MinimumWindowSubstring
	{
		string minWindow(string s, string t) {
			vector<int> toBeFound(128, 0);
			for (auto c : t) toBeFound[c]++;

			int counter = t.size();
			int start = 0;
			int end = 0;
			int minLen = INT_MAX;
			int head = 0;
			while (end < s.size()) {
				if (toBeFound[s[end]] > 0) {
					counter--;
				}
				toBeFound[s[end]]--;
				end++;

				while (counter == 0) { //valid
					if (end - start < minLen) {
						minLen = end - start;
						head = start;
					}

					toBeFound[s[start]]++;
					if (toBeFound[s[start]] > 0) {
						counter++;
					}
					start++;
				}
			}
			return minLen == INT_MAX ? "" : s.substr(head, minLen);
		}

		void Main() {
			print(minWindow("ADOBECODEBANC", "ABC"));
		}
	}
}

