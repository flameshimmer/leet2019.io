#include "stdafx.h"

//Implement a basic calculator to evaluate a simple expression string.
//The expression string may contain open ( and closing parentheses ), the plus +
//or minus sign -, non-negative integers and empty spaces .
//The expression string contains only non-negative integers, +, -, *, / operators
//, open ( and closing parentheses ) and empty spaces . The integer division
//should truncate toward zero.
//You may assume that the given expression is always valid. All intermediate
//results will be in the range of [-2147483648, 2147483647].
//Some examples:
//"1 + 1" = 2
//" 6-4 / 2 " = 4
//"2*(5+5*2)/3+(6/2+8)" = 21
//"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
// 
//
//Note: Do not use the eval built-in library function.

namespace Solution2019
{
	namespace BasicCalculatorIII
	{
		long long parseNum(string& s, int& i) {
			long long n = 0;
			while (i < s.size() && isdigit(s[i])) {
				n = n * 10 + (s[i] - '0');
				i++;
			}
			return n;
		}

		int parseExpr(string& s, int& i) {
			vector<long long> nums;
			char op = '+';
			for (; i < s.size() && op != ')'; i++) { //--> this is op!=')' instead of s[i] != ')'
				if (s[i] == ' ') { continue; }
				long long n = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
				switch (op) {
				case '+': nums.push_back(n); break;
				case '-': nums.push_back(-n); break;
				case '*': nums.back() *= n; break;
				case '/': nums.back() /= n; break;
				}
				op = s[i];
			}
			long long result = 0;
			for (long long v : nums) { result += v; }
			return result;
		}

		int calculate(string s) {
			int i = 0;
			return parseExpr(s, i);
		}

		void Main() {
			print(calculate("-1+4*3/3/3"));
		}
	}
}

