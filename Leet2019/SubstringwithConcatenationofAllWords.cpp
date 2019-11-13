#include "stdafx.h"

//You are given a string, s, and a list of words, words, that are all of the same
//length. Find all starting indices of substring(s) in s that is a concatenation
//of each word in words exactly once and without any intervening characters.
// 
//
//Example 1:
//Input:
//  s = "barfoothefoobarman",
//  words = ["foo","bar"]
//Output: [0,9]
//Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
//respectively.
//The output order does not matter, returning [9,0] is fine too.
//
//Example 2:
//Input:
//  s = "wordgoodgoodgoodbestword",
//  words = ["word","good","best","word"]
//Output: [] 

namespace Solution2019
{
	namespace SubstringwithConcatenationofAllWords
	{
		vector<int> findSubstring(string s, vector<string>& words) {
			vector<int> result;
			int lens = s.size();
			int lenw = words.size();
			if (lens == 0 || lenw == 0) { return result; }

			int len = words[0].size();
			unordered_map<string, int> toBeFound;
			for (string w : words) { toBeFound[w]++; }

			for (int i = 0; i <= lens - lenw * len; i++) {
				unordered_map<string, int> hasFound;
				int foundCount = 0;
				int start = i;
				while (start <= lens - len) {
					string cur = s.substr(start, len);
					if (toBeFound.find(cur) != toBeFound.end() && hasFound[cur] < toBeFound[cur]) {
						hasFound[cur]++;
						foundCount++;
					}
					else {
						break;
					}

					if (foundCount == lenw) {
						result.push_back(i);
						break;
					}
					start += len;
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

