#include "stdafx.h"
// Test template
//
//Input  : str = “abcba”
//	Output : Yes
//	we can remove character ‘c’ to make string palindrome
//
//	Input : str = “abcbea”
//	Output : Yes
//	we can remove character ‘e’ to make string palindrome
//
//	Input : str = “abecbea”
//	It is not possible to make this string palindrome
//	just by removing one character
namespace Solution2019
{
	namespace Test
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

				int cv2 = 0;
				if (lastop == '+') { cv2 = cv - pv + pv * v; }
				else if (lastop == '-') { cv2 = cv + pv - pv * v; }
				else { cv2 = pv * v; }
				dfs(num, i + 1, len, target, cv2, pv * v, lastop, result + "*" + cur, results);
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
			sort(results.begin(), results.end());
			return results;
		}


		namespace Another {
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
				sort(results.begin(), results.end());
				return results;
			}
		}
		void Main() {
			print(addOperators("123456789", 45));
			print(Another::addOperators("123456789", 45));
		}
	}
}
