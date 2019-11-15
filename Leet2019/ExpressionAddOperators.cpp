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
		void dfs(vector<string>& results, string& num, int target, string cur, int pos, long cv, long pv, char op) {
			if (pos == num.size() && cv == target) {
				results.push_back(cur);
			}
			else {
				for (int i = pos + 1; i <= num.size(); i++) {
					string t = num.substr(pos, i - pos);
					long now = stol(t);
					if (to_string(now).size() != t.size()) { continue; }
					dfs(results, num, target, cur + '+' + t, i, cv + now, now, '+');
					dfs(results, num, target, cur + '-' + t, i, cv - now, now, '-');

					int cv2 = 0;
					if (op == '-') { cv2 = cv + pv - pv * now; }
					else if (op == '+') { cv2 = cv - pv + pv * now; }
					else { cv2 = pv * now; }
					dfs(results, num, target, cur + '*' + t, i, cv2, pv * now, op);
				}
			}

		}

		vector<string> addOperators(string num, int target) {
			vector<string> results;
			if (num.empty()) { return results; }
			for (int i = 1; i <= num.size(); i++) {
				string s = num.substr(0, i);
				long cur = stol(s);
				if (to_string(cur).size() != s.size()) { continue; }
				dfs(results, num, target, s, i, cur, cur, '#');
			}
			return results;
		}

		void Main() {
			print(addOperators("123", 6));
		}
	}
}

