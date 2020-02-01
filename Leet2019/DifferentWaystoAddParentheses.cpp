#include "stdafx.h"

//Given a string of numbers and operators, return all possible results from
//computing all the different possible ways to group numbers and operators. The
//valid operators are +, - and *.
//
//Example 1:
//Input: "2-1-1"
//Output: [0, 2]
//Explanation: 
//((2-1)-1) = 0 
//(2-(1-1)) = 2
//
//Example 2:
//Input: "2*3-4*5"
//Output: [-34, -14, -10, -10, 10]
//Explanation: 
//(2*(3-(4*5))) = -34 
//((2*3)-(4*5)) = -14 
//((2*(3-4))*5) = -10 
//(2*((3-4)*5)) = -10 
//(((2*3)-4)*5) = 10

namespace Solution2019
{
	namespace DifferentWaystoAddParentheses
	{
		vector<int> diffWaysToCompute(string input) {
			unordered_map<string, vector<int>> map;
			return helper(input, map);
		}

		vector<int> helper(string input, unordered_map<string, vector<int>>& map) {
			vector<int> result;
			int len = input.size();

			for (int i = 0; i < len; i++) {
				char c = input[i];
				if (c == '+' || c == '-' || c == '*') {
					vector<int> result1;
					vector<int> result2;

					string h1 = input.substr(0, i);
					if (map.find(h1) != map.end()) { result1 = map[h1]; }
					else { result1 = helper(h1, map); }

					string h2 = input.substr(i + 1);
					if (map.find(h2) != map.end()) { result2 = map[h2]; }
					else { result2 = helper(h2, map); }

					for (int n1 : result1) {
						for (int n2 : result2) {
							if (c == '+') { result.push_back(n1 + n2); }
							else if (c == '-') { result.push_back(n1 - n2); }
							else { result.push_back(n1 * n2); }
						}
					}
				}
			}
			if (result.empty()) { result.push_back(stoi(input)); }
			map[input] = result;
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

