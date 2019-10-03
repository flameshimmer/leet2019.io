#include "stdafx.h"
#include <bitset>
/*Given a string, determine if a permutation 
of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true*/ 

namespace Solution2019
{
	namespace PalindromePermutation
	{
		bool canPermutePalindromeUsingBitset(string s) {
			bitset<256> bs;
			for (char c : s) {
				bs.flip(c);
			}
			return bs.count() < 2;
		}

		bool canPermutePalindrome(string s) {
			unordered_map<char, int> map;
			for (char c : s) {
				map[c] ++;
			}
			int oddCount = 0;
			for (auto& p : map) {
				if (p.second % 2) {
					oddCount++;
					if (oddCount > 1) { return false; }
				}
			}
			return true;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

