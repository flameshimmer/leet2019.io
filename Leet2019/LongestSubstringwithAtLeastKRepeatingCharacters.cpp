#include "stdafx.h"

//Find the length of the longest substring T of a given string (consists of
//lowercase letters only) such that every character in T appears no less than k
//times.
//
//Example 1:
//Input:
//s = "aaabb", k = 3
//Output:
//3
//The longest substring is "aaa", as 'a' is repeated 3 times.
//
//Example 2:
//Input:
//s = "ababbc", k = 2
//Output:
//5
//The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
//repeated 3 times.

namespace Solution2019
{
	namespace LongestSubstringwithAtLeastKRepeatingCharacters
	{
		int longestSubstring(string s, int k) {
			int len = s.size();
			if (len == 0 || len < k) { return 0; }
			if (k == 1) { return len; }
			
			int counts[26] = { 0 };
			for (char c : s) { counts[c - 'a']++; }

			char badChar = 0;
			for (int i = 0; i < 26; i++) {
				if (counts[i] > 0 && counts[i] < k) {
					badChar = 'a' + i;
					break;
				}
			}
			if (badChar == 0) { return len; }

			istringstream ss(s);
			vector<string> subs;
			string cur;
			while (getline(ss, cur, badChar)) {
				subs.push_back(cur);
			}

			int result = 0;
			for (string sub : subs) {
				result = max(result, longestSubstring(sub, k));
			}
			return result;
		}

		int longestSubstringAnother(string s, int k) {
			int len = s.size();
			int result = 0;
			for (int i = 1; i <= 26; i++) {
				int count[26] = { 0 };
				int start = 0;
				int end = 0;
				int uniqueChar = 0;
				while (end < len) {
					bool valid = true;
					if (count[s[end] - 'a'] == 0) {
						uniqueChar++;
					}
					count[s[end] - 'a'] ++;
					end++;

					while (uniqueChar > i) {
						if (count[s[start] - 'a'] == 1) {
							uniqueChar--;
						}
						count[s[start] - 'a']--;
						start++;
					}
					for (int j = 0; j < 26; j++) {
						if (count[j] > 0 && count[j] < k) { valid = false; }
					}
					if (valid) { result = max(result, end - start); }
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

