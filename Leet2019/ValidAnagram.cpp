#include "stdafx.h"
//Given two strings s and t , write a function 
//to determine if t is an anagram of s.
//
//Example 1:
//Input: s = "anagram", t = "nagaram"
//Output: true
//
//Example 2:
//Input: s = "rat", t = "car"
//Output: false
//Note:
//You may assume the string contains only lowercase alphabets.
//
//Follow up:
//What if the inputs contain unicode characters? 
//How would you adapt your solution to such case? 

namespace Solution2019
{
	namespace ValidAnagram
	{
		bool isAnagram(string s, string t) {
			if (s.size() != t.size()) { return false; }
			int map[26] = { 0 };
			for (char c : s) {
				map[c - 'a']++;
			}

			int map2[26] = { 0 };
			for (char c : t) {
				map2[c - 'a']++;
			}

			for (int i = 0; i < 26; i++) {
				if (map[i] != map2[i]) { return false; }
			}
			return true;
		}

		bool isAnagramSlower(string s, string t) {
			if (s.size() != t.size()) { return false; }
			sort(s.begin(), s.end());
			sort(t.begin(), t.end());
			return s == t;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

