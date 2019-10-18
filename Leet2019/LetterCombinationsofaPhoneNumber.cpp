#include "stdafx.h"
//Given a string containing digits from 2-9 inclusive, return 
//all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) 
//is given below. Note that 1 does not map to any letters.
//
//Example:
//Input: "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//Note:
//Although the above answer is in lexicographical order, 
//your answer could be in any order you want.

namespace Solution2019
{
	namespace LetterCombinationsofaPhoneNumber
	{
		namespace Recursive {
			void helper(string& digits, int start, int len, string* can, string& result, vector<string>& results) {
				if (start == len) {
					results.push_back(result);
					return;
				}

				int index = digits[start] - '0';
				for (int i = 0; i < can[index].size(); i++) {
					result.push_back(can[index][i]);
					helper(digits, start + 1, len, can, result, results);
					result.pop_back();
				}
			}

			vector<string> letterCombinations(string digits) {
				string candidate[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
				vector<string> results;
				int len = digits.size();
				if (len == 0) { return results; }

				string result = "";
				helper(digits, 0, len, candidate, result, results);
				return results;
			}
		}

		namespace Iterative {
			vector<string> letterCombinations(string digits) {
				vector<string> result;
				int len = digits.size();
				if (len == 0) { return result; }

				vector<string> v = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

				result.push_back("");

				for (int i = 0; i < len; i++) {
					int num = digits[i] - '0';
					string& candidate = v[num];

					vector<string> tmp;
					for (char c : candidate) {
						for (string r : result) {
							tmp.push_back(r + c);
						}
					}
					result.swap(tmp);
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

