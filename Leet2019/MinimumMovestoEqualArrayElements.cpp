#include "stdafx.h"
/*Given a non-empty integer array of size n, find the minimum 
number of moves required to make all array elements equal, 
where a move is incrementing n - 1 elements by 1.

Example:
Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed 
(remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]*/ 

namespace Solution2019
{
	namespace MinimumMovestoEqualArrayElements
	{
		//Adding 1 to(n - 1) elements is equivalent to subtracting 1 from one
		//of the elements and adding 1 to all elements.Adding 1 to all elements
		//does not change anything in terms of equality.So we must find the min
		//number of(subtract 1 from any element) operations.The only way to make
		//all elements equal this way is to make them all equal to the min element
		//of the array. Hence, number of moves = sum(array) - n * min_element
		int minMoves(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return 0; }

			long long sum = 0;
			for (int v : nums) {
				sum += v;
			}

			int min = *min_element(nums.begin(), nums.end());
			return sum - long(min) * long(len);
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

