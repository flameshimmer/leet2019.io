#include "stdafx.h"

//A strobogrammatic number is a number that looks the same when rotated 180
//degrees (looked at upside down).
//Find all strobogrammatic numbers that are of length = n.
//
//Example:
//Input:  n = 2
//Output: ["11","69","88","96"] 

namespace Solution2019
{
	namespace StrobogrammaticNumberII
	{
		// Time complexity 5^(N/2)
		vector<string> helper(int targetLevel, int curLevel) {
			if (curLevel == 0) { return { "" }; }
			if (curLevel == 1) { return { "0", "1", "8" }; }

			vector<string> innerResult = helper(targetLevel, curLevel - 2);
			vector<string> result;
			for (string& r : innerResult) {
				if (targetLevel != curLevel) {
					result.push_back("0" + r + "0");
				}
				result.push_back("1" + r + "1");
				result.push_back("8" + r + "8");
				result.push_back("6" + r + "9");
				result.push_back("9" + r + "6");
			}
			return result;
		}


		vector<string> findStrobogrammatic(int n) {
			return helper(n, n);
		}

		namespace Another {
			void helper(int n, vector<pair<int, int>>& match, string h1, string h2, vector<string>& results) {
				if (!h1.empty() && h1[0] == '0') { return; }
				if (n <= 1) {
					if (n == 0) { results.push_back(h1 + h2); }
					else {
						for (pair<int, int> p : match) {
							if (p.first == p.second) { results.push_back(h1 + to_string(p.first) + h2); }
						}
					}
					return;
				}

				for (auto& p : match) {
					helper(n - 2, match, h1 + to_string(p.first), to_string(p.second) + h2, results);
				}
			}

			vector<string> findStrobogrammatic(int n) {
				if (n == 0) { return {}; }
				vector<pair<int, int>> match = { {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6} };
				vector<string> results;
				helper(n, match, "", "", results);
				return results;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

