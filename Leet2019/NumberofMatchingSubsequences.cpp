#include "stdafx.h"
//Given string S and a dictionary of words words, 
//find the number of words[i] that is a subsequence of S.
//
//Example :
//Input: 
//S = "abcde"
//words = ["a", "bb", "acd", "ace"]
//Output: 3
//	Explanation: There are three words in words that are 
//	a subsequence of S: "a", "acd", "ace".
//Note:
//
//All words in words and S will only consists of lowercase letters.
//The length of S will be in the range of [1, 50000].
//The length of words will be in the range of [1, 5000].
//The length of words[i] will be in the range of [1, 50].

namespace Solution2019
{
	namespace NumberofMatchingSubsequences
	{
		bool isSubseq(string& w, vector<vector<int>>& map, unordered_map<string, bool>& cache) {

			if (cache.count(w)) { return cache[w]; }
			int lastIndex = -1;
			int len = w.size();
			for (char c : w) {
				vector<int>& pos = map[c];
				auto it = lower_bound(pos.begin(), pos.end(), lastIndex + 1);
				if (it == pos.end()) { cache[w] = false; return false; }
				lastIndex = *it;
			}
			cache[w] = true;
			return true;
		}

		int numMatchingSubseq(string S, vector<string>& words) {
			vector<vector<int>> myMap(128);
			unordered_map<string, bool> cache;
			for (int i = 0; i < S.size(); i++) {
				myMap[S[i]].push_back(i);
			}

			int count = 0;
			for (string w : words) {
				if (isSubseq(w, myMap, cache)) {
					count++;
				}
			}
			return count;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

