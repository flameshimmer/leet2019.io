#include "stdafx.h"
//Given a string S of lowercase letters, a duplicate removal
//consists of choosing two adjacent and equal letters, and removing them.
//
//We repeatedly make duplicate removals on S until we no longer can.
//
//Return the final string after all such duplicate removals have 
//been made.  It is guaranteed the answer is unique.
//
//Example 1:
//Input: "abbaca"
//Output: "ca"
//Explanation: 
//For example, in "abbaca" we could remove "bb" since the letters are 
//adjacent and equal, and this is the only possible move.  The result
//of this move is that the string is "aaca", of which only "aa" is 
//possible, so the final string is "ca".
// 
//Note:
//1 <= S.length <= 20000
//S consists only of English lowercase letters.

namespace Solution2019
{
	namespace RemoveAllAdjacentDuplicatesInString
	{
		string removeDuplicates(string S) {
			string a;
			for (char c : S) {
				if (a.size() > 0 && a.back() == c) { a.pop_back(); }
				else { a += c; }
			}
			return a;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

