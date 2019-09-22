#include "stdafx.h"
//Given an array A of positive integers, A[i] represents the 
//value of the i-th sightseeing spot, and two sightseeing 
//spots i and j have distance j - i between them.
//
//The score of a pair (i < j) of sightseeing spots is 
//(A[i] + A[j] + i - j) : the sum of the values of the 
//sightseeing spots, minus the distance between them.
//
//Return the maximum score of a pair of sightseeing spots.
//
// 
//
//Example 1:
//Input: [8,1,5,2,6]
//Output: 11
//	Explanation: i = 0, j = 2,
//	A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
// 
//Note:
//2 <= A.length <= 50000
//1 <= A[i] <= 1000
namespace Solution2019
{
	namespace BestSightseeingPair
	{
		int maxScoreSightseeingPair(vector<int>& A) {
			int result = 0;
			int prevBest = 0;

			for (int a : A) {
				result = max(result, prevBest + a);
				prevBest = max(prevBest, a) - 1;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

