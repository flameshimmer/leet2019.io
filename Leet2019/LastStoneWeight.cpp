#include "stdafx.h"
/*We have a collection of rocks, each rock has a positive 
integer weight.

Each turn, we choose the two heaviest rocks and smash them
together.  Suppose the stones have weights x and y with x <= y.  
The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the
stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight 
of this stone (or 0 if there are no stones left.)

Example 1:
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then 
that's the value of last stone.
 
Note:
1 <= stones.length <= 30
1 <= stones[i] <= 1000*/ 

namespace Solution2019
{
	namespace LastStoneWeight
	{
		int lastStoneWeight(vector<int>& stones) {
			priority_queue<int> q(begin(stones), end(stones));
			while (q.size() > 1) {
				int v1 = q.top();
				q.pop();
				int v2 = q.top();
				q.pop();
				if (v1 != v2) { q.push(v1 - v2); }
			}
			return q.empty() ? 0 : q.top();
		}

		int lastStoneWeightAnother(vector<int>& stones) {
			priority_queue<int> q;
			for (int v : stones) { q.push(v); }

			while (!q.empty())
			{
				int v1 = q.top();
				q.pop();
				if (q.empty()) { return v1; }
				int v2 = q.top();
				q.pop();
				if (v1 != v2) { q.push(v1 - v2); }
			}
			return 0;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

