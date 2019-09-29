#include "stdafx.h"
//Given an array A, partition it into two (contiguous) subarrays left and right so that:
//
//Every element in left is less than or equal to every element in right.
//left and right are non-empty.
//left has the smallest possible size.
//Return the length of left after such a partitioning.  
//It is guaranteed that such a partitioning exists.
//
//Example 1:
//Input: [5,0,3,8,6]
//Output: 3
//Explanation: left = [5,0,3], right = [8,6]
//
//Example 2:
//Input: [1,1,1,0,6,12]
//Output: 4
//Explanation: left = [1,1,1,0], right = [6,12]
// 
//Note:
//2 <= A.length <= 30000
//0 <= A[i] <= 10^6
//It is guaranteed there is at least one way to partition A as described.

namespace Solution2019
{
	namespace PartitionArrayintoDisjointIntervals
	{
		int partitionDisjoint(vector<int>& A) {
			int len = A.size();
			int maxV = INT_MIN;
			int minV = INT_MAX;
			vector<int> maxLeft(len);
			vector<int> minRight(len);
			for (int i = 0; i < len; i++) {
				maxV = max(maxV, A[i]);
				maxLeft[i] = maxV;

				minV = min(minV, A[len - 1 - i]);
				minRight[len - 1 - i] = minV;
			}

			for (int i = 1; i < len; i++) {
				if (maxLeft[i - 1] <= minRight[i]) {
					return i;
				}
			}
			return -1;

		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

