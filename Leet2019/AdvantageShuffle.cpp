#include "stdafx.h"
//Given two arrays A and B of equal size, the advantage 
//of A with respect to B is the number of indices i for which A[i] > B[i].
//
//Return any permutation of A that maximizes its advantage with respect to B.
//
//Example 1:
//Input: A = [2,7,11,15], B = [1,10,4,11]
//Output: [2,11,7,15]
//
//Example 2:
//Input: A = [12,24,8,32], B = [13,25,32,11]
//Output: [24,32,8,12]
//
//Note:
//1 <= A.length = B.length <= 10000
//0 <= A[i] <= 10^9
//0 <= B[i] <= 10^9 

namespace Solution2019
{
	namespace AdvantageShuffle
	{
		vector<int> advantageCountUsingMultiMap(vector<int>& A, vector<int>& B) {
			multiset<int> set(A.begin(), A.end());
			for (int i = 0; i < A.size(); i++) {
				auto it = *set.rbegin() > B[i] ? set.upper_bound(B[i]) : set.begin();
				A[i] = *it;
				set.erase(it);
			}
			return A;
		}

		vector<int> advantageCountUsingMap(vector<int>& A, vector<int>& B) {
			map<int, int> map;
			for (int v : A) { map[v]++; }

			for (int i = 0; i < B.size(); i++) {
				auto it = map.upper_bound(B[i]);
				int x = it == map.end() ? map.begin()->first : it->first;
				A[i] = x;
				map[x]--;
				if (map[x] == 0) { map.erase(x); }
			}
			return A;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

