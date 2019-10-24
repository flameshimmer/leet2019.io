#include "stdafx.h"
//Given a non-empty array of integers, return the k most frequent elements.
//
//Example 1:
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), 
//where n is the array's size. 

namespace Solution2019
{
	namespace TopKFrequentElements
	{
		vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int, int> map;
			for (int v : nums) { map[v]++; }

			auto comp = [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second; };
			priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
			for (auto& p : map) {
				pq.push(make_pair(p.first, p.second));
				if (pq.size() > k) { pq.pop(); }
			}
			vector<int> result;
			while (!pq.empty()) {
				result.push_back(pq.top().first);
				pq.pop();
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

