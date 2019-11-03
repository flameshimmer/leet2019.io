#include "stdafx.h"

//Given a string containing only digits, restore it by returning all possible
//valid IP address combinations.
//
//Example:
//Input: "25525511135"
//Output: ["255.255.11.135", "255.255.111.35"]

namespace Solution2019
{
	namespace RestoreIPAddresses
	{
		void helper(string& s, int start, int len, int level, string result, vector<string>& results) {
			if (start == len) {
				if (level == 0) {
					result.pop_back();
					results.push_back(result);
				}
				return;
			}
			if (len - start < level || len - start > 3 * level) { return; }

			int possibleLen = s[start] == '0' ? 1 : 3;
			for (int i = 1; i <= possibleLen; i++) {
				string tmp = s.substr(start, i);
				if (stoi(tmp) > 255) { break; }
				helper(s, start + i, len, level - 1, result + tmp + '.', results);
			}
		}

		vector<string> restoreIpAddresses(string s) {
			int len = s.size();
			vector<string> results;

			string result;
			helper(s, 0, len, 4, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

