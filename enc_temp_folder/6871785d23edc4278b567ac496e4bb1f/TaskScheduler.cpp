#include "stdafx.h"
//Given a char array representing tasks CPU need to do. It contains 
//capital letters A to Z where different letters represent different
//tasks. Tasks could be done without original order. Each task
//could be done in one interval. For each interval, CPU could 
//finish one task or just be idle.
//
//However, there is a non-negative cooling interval n that means
//between two same tasks, there must be at least n intervals 
//that CPU are doing different tasks or just be idle.
//
//You need to return the least number of intervals the CPU will
//take to finish all the given tasks.
//
//Example:
//Input: tasks = ["A","A","A","B","B","B"], n = 2
//Output: 8
//Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
// 
//Note:
//The number of tasks is in the range [1, 10000].
//The integer n is in the range [0, 100].

namespace Solution2019
{
	namespace TaskScheduler
	{
		int leastInterval(vector<char>& tasks, int n) {
			unordered_map<char, int> work;
			for (char c : tasks) { work[c] ++; }

			int result = tasks.size();
			while (!work.empty()) {
				int N = 0;
				for (auto& p : work) {
					p.second--;
					if (p.second == 0) { work.erase(p.first); }
					N++;
					if (N == n) { break; }
				}
				result += n - N;
			}
			return result;
		}

		void Main() {
			vector<char> test = { 'A', 'A', 'A', 'B', 'B', 'B'};
			print(leastInterval(test, 2));
		}
	}
}

