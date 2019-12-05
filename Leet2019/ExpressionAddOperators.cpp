#include "stdafx.h"

//Given a string that contains only digits 0-9 and a target value, return all
//possibilities to add binary operators (not unary) +, -, or * between the digits
//so they evaluate to the target value.
//
//Example 1:
//Input: num = "123", target = 6
//Output: ["1+2+3", "1*2*3"] 
//
//Example 2:
//Input: num = "232", target = 8
//Output: ["2*3+2", "2+3*2"]
//
//Example 3:
//Input: num = "105", target = 5
//Output: ["1*0+5","10-5"]
//
//Example 4:
//Input: num = "00", target = 0
//Output: ["0+0", "0-0", "0*0"]
//
//Example 5:
//Input: num = "3456237490", target = 9191
//Output: [] 

namespace Solution2019
{
	namespace ExpressionAddOperators
	{
		void dfs(string& num, int start, int len, int target, long cv, long pv, char lastop, string result, vector<string>& results) {
			if (start == len && cv == target) {
				results.push_back(result);
				return;
			}

			for (int i = start; i < len; i++) {
				string cur = num.substr(start, i - start + 1);
				long v = stol(cur);
				if (cur.size() != to_string(v).size()) { continue; }

				dfs(num, i + 1, len, target, cv + v, v, '+', result + "+" + cur, results);
				dfs(num, i + 1, len, target, cv - v, v, '-', result + "-" + cur, results);

				long cv2 = 0;
				if (lastop == '+') { cv2 = cv - pv + pv * v; }
				else if (lastop == '-') { cv2 = cv + pv - pv * v; }
				else { cv2 = pv * v; }
				dfs(num, i + 1, len, target, cv2, pv * v, lastop, result + '*' + cur, results);
			}
		}

		vector<string> addOperators(string num, int target) {
			vector<string> results;
			int len = num.size();
			if (len == 0) { return results; }

			for (int i = 1; i <= len; i++) {
				string s = num.substr(0, i);
				long v = stol(s);
				if (s.size() != to_string(v).size()) { continue; }
				dfs(num, i, len, target, v, v, '#', s, results);
			}
			return results;
		}

		void Main() {
			print(addOperators("123", 6));
		}
	}
}

