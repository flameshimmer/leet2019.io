#include "stdafx.h"
//Given an array of integers A with even length, return true if 
//and only if it is possible to reorder it such that 
//A[2 * i + 1] = 2 * A[2 * i] for every 0 <= i < len(A) / 2.
//
//Example 1:
//Input: [3,1,3,6]
//Output: false
//
//Example 2:
//Input: [2,1,2,6]
//Output: false
//
//Example 3:
//Input: [4,-2,2,-4]
//Output: true
//Explanation: We can take two groups, [-2,-4] and [2,4] 
//to form [-2,-4,2,4] or [2,4,-2,-4].
//
//Example 4:
//Input: [1,2,4,16,8,4]
//Output: false
//
//Note:
//0 <= A.length <= 30000
//A.length is even
//-100000 <= A[i] <= 100000

namespace Solution2019
{
	namespace ArrayofDoubledPairs
	{
		bool canReorderDoubled(vector<int>& A) {
			unordered_map<int, int> map;
			for (int v : A) { map[v]++; }

			vector<int> B;
			for (auto& p : map) { B.push_back(p.first); }

			auto comp = [](int a, int b) {return abs(a) < abs(b); };
			sort(B.begin(), B.end(), comp);

			for (int v : B) {
				if (map[v] > map[2 * v]) { return false; }
				map[2 * v] -= map[v];
			}
			return true;
		}

		bool canReorderDoubledSlow(vector<int>& A) {
			unordered_map<int, int> map;
			for (int v : A) { map[v]++; }

			auto comp = [](int a, int b) {return abs(a) < abs(b); };
			sort(A.begin(), A.end(), comp);

			for (int i = 0; i < A.size(); i++) {
				if (map[A[i]] == 0) { 
					continue; 
				}
				if (map[2 * A[i]] == 0) { return false; }
				map[A[i]] --;
				map[2 * A[i]]--;
			}
			return true;
		}
		void Main() {
			vector<int> test = {2, -2, 4, -4};
			print(canReorderDoubled(test));
		}
	}
}

