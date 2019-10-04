#include "stdafx.h"
//Given a string S, we can transform every letter individually 
//to be lowercase or uppercase to create another string.  
//Return a list of all possible strings we could create.
//
//Examples:
//Input: S = "a1b2"
//Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
//Input: S = "3z4"
//Output: ["3z4", "3Z4"]
//
//Input: S = "12345"
//Output: ["12345"]
//Note:
//
//S will be a string with length between 1 and 12.
//S will consist only of letters or digits.

namespace Solution2019
{
	namespace LetterCasePermutation
	{
		void helper(string& S, int start, int len, string result, vector<string>& results) {
			if (start == len) {
				results.push_back(result);
				return;
			}

			if (isdigit(S[start])) {
				helper(S, start + 1, len, result + S[start], results);
			}
			else {
				char lower = tolower(S[start]);
				helper(S, start + 1, len, result + lower, results);
				char upper = toupper(S[start]);
				helper(S, start + 1, len, result + upper, results);
			}
		}

		vector<string> letterCasePermutation(string S) {
			vector<string> results;
			int len = S.size();
			if (len == 0) { return results; }

			helper(S, 0, len, "", results);
			return results;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

