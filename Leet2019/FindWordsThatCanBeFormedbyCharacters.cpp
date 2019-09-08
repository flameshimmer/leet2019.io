#include "stdafx.h"
//You are given an array of strings words and a string chars.
//A string is good if it can be formed by characters from 
//chars (each character can only be used once).
//Return the sum of lengths of all good strings in words.
//
//Example 1:
//Input: words = ["cat","bt","hat","tree"], chars = "atach"
//Output: 6
//Explanation: 
//The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
//
//Example 2:
//Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
//Output: 10
//Explanation: 
//The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
// 
//Note:
//1 <= words.length <= 1000
//1 <= words[i].length, chars.length <= 100
//All strings contain lowercase English letters only.

namespace Solution2019
{
	namespace FindWordsThatCanBeFormedbyCharacters
	{
		int countCharInternal(string word, string chars) {
			if (word.size() > chars.size()) { return 0; }
			char map[26] = { 0 };
			for (char c : chars) { map[c-'a']++; }
			for (char c : word) {
				if (map[c-'a'] > 0) { map[c-'a']--; }
				else { return 0; }
			}
			return word.size();
		}

		int countCharacters(vector<string>& words, string chars) {
			int sum = 0;
			for (string w : words) {
				sum += countCharInternal(w, chars);
			}
			return sum;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

