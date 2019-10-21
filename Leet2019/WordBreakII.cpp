#include "stdafx.h"
//Given a non-empty string s and a dictionary wordDict containing a list of 
//non-empty words, add spaces in s to construct a sentence where each word 
//is a valid dictionary word. Return all such possible sentences.
//
//Note:
//The same word in the dictionary may be reused multiple times in the segmentation.
//You may assume the dictionary does not contain duplicate words.
//
//Example 1:
//Input:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//Output:
//[
//  "cats and dog",
//  "cat sand dog"
//]
//
//Example 2:
//Input:
//s = "pineapplepenapple"
//wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//Output:
//[
//  "pine apple pen apple",
//  "pineapple pen apple",
//  "pine applepen apple"
//]
//Explanation: Note that you are allowed to reuse a dictionary word.
//
//Example 3:
//Input:
//s = "catsandog"
//wordDict = ["cats", "dog", "sand", "and", "cat"]
//Output:
//[]

namespace Solution2019
{
	namespace WordBreakII
	{
		void breakWord(string& s, int len, int start, unordered_set<string>& dict, string result, vector<string>& results, vector<bool>& P) {
			if (start >= len) {
				result.pop_back();
				results.push_back(result);
			}
			for (int i = start; i < len; i++) {
				string cur = s.substr(start, i - start + 1);
				if (dict.find(cur) != dict.end() && P[i + 1]) {
					int oldSize = results.size();
					breakWord(s, len, i + 1, dict, result + cur + " ", results, P);
					if (results.size() == oldSize) { P[i + 1] = false; }
				}
			}
		}

		vector<string> wordBreak(string s, vector<string>& wordDict) {
			int len = s.size();
			unordered_set<string> dict(wordDict.begin(), wordDict.end());
			vector<string> results;
			string result;
			vector<bool> P(len + 1, true);
			breakWord(s, len, 0, dict, result, results, P);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

