#include "stdafx.h"

////Given a binary array, find the maximum number of consecutive 1s in this array
////if you can flip at most one 0.
////
////
//Example 1:
////Input: [1,0,1,1,0]
////Output: 4
////Explanation: Flip the first zero will get the the maximum number of
//consecutive
////1s.
////    After flipping, the maximum number of consecutive 1s is 4.
////
////
//Note:
////The input array will only contain 0 and 1.
////The length of input array is a positive integer and will not exceed 10,000
////Follow up:
////What if the input numbers come in one by one as an infinite stream? In other
////words, you can't store all numbers coming from the stream as it's too large
//to
////hold in memory. Could you solve it efficiently?

namespace Solution2019
{
	namespace MaxConsecutiveOnesII
	{
		int findMaxConsecutiveOnes(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int k = 1;
			int result = 0;

			int start = 0;
			for (int end = 0; end < len; end++) {
				if (nums[end] == 0) { k--; }
				while (k < 0) {
					if (nums[start] == 0) { k++; }
					start++;
				}
				result = max(result, end - start + 1);
			}
			return result;
		}

		namespace FollowUpIfInputIsInfinit {
			int findMaxConsecutiveOnes(vector<int>& nums) {
				int result = 0;
				int start = 0;
				list<int> l;
				int k = 1;
				for (int end = 0; end < nums.size(); end++) {
					if (nums[end] == 0) { l.push_back(end); k--; }
					while (k < 0) {
						start = l.front() + 1;
						l.pop_front();
						k++;
					}
					result = max(result, end - start + 1);
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

