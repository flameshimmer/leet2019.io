#include "stdafx.h"
//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
//determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
//Note:
//The same word in the dictionary may be reused multiple times in the segmentation.
//You may assume the dictionary does not contain duplicate words.
//
//Example 1:
//Input: s = "leetcode", wordDict = ["leet", "code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".
//
//Example 2:
//Input: s = "applepenapple", wordDict = ["apple", "pen"]
//Output: true
//Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//             Note that you are allowed to reuse a dictionary word.
//
//Example 3:
//Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//Output: false 

namespace Solution2019
{
	namespace WordBreak
	{
		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> dict(wordDict.begin(), wordDict.end());
			int lens = s.size();
			if (lens == 0) { return false; }
			int len = dict.size();
			if (len == 0) { return false; }

			vector<bool> M(lens + 1, false);
			M[0] = true;
			for (int i = 1; i <= lens; i++) {
				for (int j = 0; j < i; j++) {
					if (M[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
						M[i] = true;
						break;
					}
				}
			}
			return M[lens];
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

