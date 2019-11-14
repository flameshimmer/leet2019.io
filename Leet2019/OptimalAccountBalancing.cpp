#include "stdafx.h"

//A group of friends went on holiday and sometimes lent each other money. For
//example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5
//for a taxi ride. We can model each transaction as a tuple (x, y, z) which means
//person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and
//2 respectively (0, 1, 2 are the person's ID), the transactions can be
//represented as [[0, 1, 10], [2, 0, 5]].
//Given a list of transactions between a group of people, return the minimum
//number of transactions required to settle the debt.
//
//Note:
//A transaction will be given as a tuple (x, y, z). 
//Note that x ≠ y and z > 0.
//Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we
//could also have the persons 0, 2, 6.
//
//Example 1:
//Input:
//[[0,1,10], [2,0,5]]
//Output:
//2
//Explanation:
//Person #0 gave person #1 $10.
//Person #2 gave person #0 $5.
//Two transactions are needed. One way to settle the debt is person #1 pays
//person #0 and #2 $5 each.
//
//Example 2:
//Input:
//[[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
//Output:
//1
//Explanation:
//Person #0 gave person #1 $10.
//Person #1 gave person #0 $1.
//Person #1 gave person #2 $5.
//Person #2 gave person #0 $5.
//Therefore, person #1 only need to give person #0 $4, and all debt is settled.

namespace Solution2019
{
	namespace OptimalAccountBalancing
	{
		int dfs(vector<int>& list, int start, int len) {
			if (start == len) { return 0; }

			int cur = list[start];
			if (cur == 0) { return dfs(list, start + 1, len); }

			int minV = INT_MAX;
			for (int i = start + 1; i < len; i++) {
				int next = list[i];
				if (cur * next < 0) {
					list[i] = cur + next;
					minV = min(minV, 1 + dfs(list, start + 1, len));
					list[i] = next;
					if (cur + next == 0) { break; }
				}
			}
			return minV;
		}


		int minTransfers(vector<vector<int>>& transactions) {
			int len = transactions.size();
			if (len < 2) { return len; }

			unordered_map<int, int> map; //person, final total
			for (vector<int>& t : transactions) {
				map[t[0]] -= t[2];
				map[t[1]] += t[2];
			}
			vector<int> list;
			for (auto& p : map) {
				if (p.second != 0) { list.push_back(p.second); }
			}

			return dfs(list, 0, list.size());
		}
		void Main() {
			vector<vector<int>> test = { {0,1,10},{2,0,5} };
			print(minTransfers(test));
		}
	}
}

