#include "stdafx.h"
//In an alien language, surprisingly they also use english lowercase letters, 
//but possibly in a different order. The order of the alphabet is some 
//permutation of lowercase letters.
//
//Given a sequence of words written in the alien language, and the order 
//of the alphabet, return true if and only if the given words are sorted
//lexicographicaly in this alien language.
//
//Example 1:
//Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
//Output: true
//Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
//
//Example 2:
//Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
//Output: false
//Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], 
//hence the sequence is unsorted.
//
//Example 3:
//Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
//Output: false
//Explanation: The first three characters "app" match, and the second string is
//shorter (in size.) According to lexicographical rules "apple" > "app", 
//because 'l' > '∅', where '∅' is defined as the blank character which is 
//less than any other character (More info).
//
//Note:
//1 <= words.length <= 100
//1 <= words[i].length <= 20
//order.length == 26
//All characters in words[i] and order are english lowercase letters. 

namespace Solution2019
{
	namespace VerifyinganAlienDictionary
	{
		bool isAlienSorted(vector<string>& words, string order) {
			unordered_map<char, int> map;
			for (int i = 0; i < order.size(); i++) {
				map[order[i]] = i;
			}

			auto comp = [&map](string& w1, string& w2) {
				int len1 = w1.size();
				int len2 = w2.size();
				for (int i = 0; i < min(len1, len2); i++) {
					if (w1[i] != w2[i]) {
						return map[w1[i]] < map[w2[i]];
					}
				}
				return len1 < len2;
			};
			return is_sorted(words.begin(), words.end(), comp);
		}

		bool isAlienSortedAnother(vector<string>& words, string order) {
			int map[26] = { 0 };
			for (int i = 0; i < 26; i++) {
				map[order[i] - 'a'] = i;
			}

			for (string& w : words) {
				for (char& c : w) {
					c = map[c - 'a'];
				}
			}
			return is_sorted(words.begin(), words.end());
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

