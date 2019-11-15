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
		int evaluate(string s) {
			int len = s.size();
			int result = 0;
			bool mul = false;
			bool isNeg = false;
			int prev = 0;
			for (int i = 0; i < len; i++) {
				char c = s[i];
				switch (c) {
				case '+':
					result += isNeg ? -prev : prev;
					isNeg = false;
					break;
				case '-':
					result += isNeg ? -prev : prev;
					isNeg = true;
					break;
				case '*':
					mul = true;
					break;
				default:
					int val = c - '0';
					if (mul) { prev *= val; }
					else { prev = val; }
					mul = false;
				}
			}
			result += isNeg ? -prev : prev;
			return result;
		}


		vector<char> ops = { '+', '-', '*' };

		void helper(string& num, int start, int len, int target, string result, vector<string>& results) {
			if (start == len) {
				if (evaluate(result) == target) { results.push_back(result); }
				return;
			}

			for (char op : ops) {
				helper(num, start + 1, len, target, result + op + num[start], results);
			}
		}



		vector<string> addOperators(string num, int target) {
			int len = num.size();
			if (len == 0) { return {}; }
			vector<string> results;
			string result = "";
			result += num[0];
			helper(num, 1, len, target, result, results);
			return results;
		}
		void Main() {
			print(addOperators("123", 6));
		}
	}
}

