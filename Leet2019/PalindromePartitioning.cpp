#include "stdafx.h"

//Given a string s, partition s such that every substring of the partition is a
//palindrome.
//Return all possible palindrome partitioning of s.
//
//Example:
//Input: "aab"
//Output:
//[
//  ["aa","b"],
//  ["a","a","b"]
//]

namespace Solution2019
{
	namespace PalindromePartitioning
	{
		bool isValid(string& s, int start, int end) {
			while (start < end) {
				if (s[start] != s[end]) { return false; }
				start++;
				end--;
			}
			return true;
		}

		void helper(string& s, int start, int len, vector<string>& result, vector<vector<string>>& results) {
			if (start == len) {
				results.push_back(result);
				return;
			}

			for (int i = start; i < len; i++) {
				if (isValid(s, start, i)) {
					string cur = s.substr(start, i - start + 1);
					result.push_back(cur);
					helper(s, i + 1, len, result, results);
					result.pop_back();
				}
			}
		}

		vector<vector<string>> partition(string s) {
			vector<vector<string>> results;
			int len = s.size();
			if (len == 0) { return results; }

			vector<string> result;
			helper(s, 0, len, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

