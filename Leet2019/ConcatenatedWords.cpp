#include "stdafx.h"
//Given a list of words (without duplicates), please write a program that 
//returns all concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of 
//at least two shorter words in the given array.
//
//Example:
//Input: 
//["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//
//Explanation: 
//"catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
//"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//
//Note:
//The number of elements of the given array will not exceed 10,000
//The length sum of elements in the given array will not exceed 600,000.
//All the input string will only include lower case letters.
//The returned elements order does not matter.

namespace Solution2019
{
	namespace ConcatenatedWords
	{
		bool formWord(string& s, unordered_set<string>& dict) {
			if (s.empty()) { return false; }

			int len = s.size();
			vector<bool> dp(len + 1, false);
			dp[0] = true;
			for (int i = 1; i <= len; i++) {
				for (int j = 0; j < i; j++) {
					if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
						dp[i] = true;
						break;
					}
				}
			}
			return dp[len];
		}

		vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
			vector<string> result;
			unordered_set<string> dict;
			sort(words.begin(), words.end(), [](string& a, string& b) {return a.size() < b.size(); });
			for (string& w : words) {
				if (formWord(w, dict)) {
					result.push_back(w);
				}
				dict.insert(w);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

