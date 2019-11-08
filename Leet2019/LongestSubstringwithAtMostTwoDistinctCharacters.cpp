#include "stdafx.h"

//Given a string, find the length of the longest substring T that contains at
//most k distinct characters.
//
//Example 1:
//Input: s = "eceba", k = 2
//Output: 3
//Explanation: T is "ece" which its length is 3.
//
//Example 2:
//Input: s = "aa", k = 1
//Output: 2
//Explanation: T is "aa" which its length is 2.

namespace Solution2019
{
	namespace LongestSubstringwithAtMostTwoDistinctCharacters
	{
		int lengthOfLongestSubstringKDistinct(string s, int k) {
			int len = s.size();
			if (k == 0 || len == 0) { return 0; }
			if (k >= len) { return len; }

			unordered_map<char, int> map;
			int start = 0;
			int end = 0;
			int result = 0;
			while (end < len) {
				map[s[end]]++;
				if (map.size() > k) {
					result = max(result, end - start);
					while (map.size() > k) {
						char c = s[start];
						map[c]--;
						if (map[c] == 0) { map.erase(c); }
						start++;
					}
				}
				end++;
			}
			result = max(result, end - start);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

