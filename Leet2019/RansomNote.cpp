#include "stdafx.h"
//Given an arbitrary ransom note stringand another string
//containing letters from all the magazines, write a 
//function that will return true if the ransom note can be
//constructed from the magazines; otherwise, it will return false.
//
//Each letter in the magazine string can only be used once 
//in your ransom note.
//
//Note:
//You may assume that both strings contain only lowercase letters.
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true

namespace Solution2019
{
	namespace RansomNote
	{
		bool canConstruct(string ransomNote, string magazine) {
			int map[26] = { 0 };
			for (char c : magazine) {
				map[c - 'a']++;
			}

			for (char c : ransomNote) {
				map[c - 'a']--;
				if (map[c - 'a'] < 0) { return false; }
			}
			return true;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

