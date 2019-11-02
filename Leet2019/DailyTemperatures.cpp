#include "stdafx.h"

//Given a list of daily temperatures T, return a list such that, for each day in
//the input, tells you how many days you would have to wait until a warmer
//temperature. If there is no future day for which this is possible, put 0
//instead.
//For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
//73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
//
//Note: The length of temperatures will be in the range [1, 30000]. Each
//temperature will be an integer in the range [30, 100]. 

namespace Solution2019
{
	namespace DailyTemperatures
	{
		vector<int> dailyTemperatures(vector<int>& T) {
			int len = T.size();
			if (len == 0) { return {}; }

			vector<int> result(len, 0);
			stack<int> s;
			for (int i = 0; i < T.size(); i++) {
				while (!s.empty() && T[i] > T[s.top()]) {
					int cur = s.top();
					s.pop();
					result[cur] = i - cur;
				}
				s.push(i);
			}
			return result;
		}

		void Main() {
			vector<int> test = { 73,74,75,71,69,72,76,73 };
			print(dailyTemperatures(test));
		}
	}
}

