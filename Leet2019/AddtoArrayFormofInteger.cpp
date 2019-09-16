#include "stdafx.h"
//For a non-negative integer X, the array-form of X is an 
//array of its digits in left to right order.  For example,
//if X = 1231, then the array form is [1,2,3,1].
//
//Given the array-form A of a non-negative integer X, 
//return the array-form of the integer X+K.
//
//Example 1:
//Input: A = [1,2,0,0], K = 34
//Output: [1,2,3,4]
//Explanation: 1200 + 34 = 1234
//Example 2:
//
//Input: A = [2,7,4], K = 181
//Output: [4,5,5]
//Explanation: 274 + 181 = 455
//
//Example 3:
//Input: A = [2,1,5], K = 806
//Output: [1,0,2,1]
//Explanation: 215 + 806 = 1021
//
//Example 4:
//Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
//Output: [1,0,0,0,0,0,0,0,0,0,0]
//Explanation: 9999999999 + 1 = 10000000000
// 
//Note：
//1 <= A.length <= 10000
//0 <= A[i] <= 9
//0 <= K <= 10000
//If A.length > 1, then A[0] != 0 

namespace Solution2019
{
	namespace AddtoArrayFormofInteger
	{
		vector<int> addToArrayForm(vector<int> A, int K) {
			vector<int> result;
			int len = A.size();
			int i = len - 1;
			int carry = 0;
			while (K > 0 || carry > 0 || i >=0) {
				int sum = (K > 0 ? K % 10 : 0) + (i>=0 ? A[i]: 0) + carry;
				carry = sum / 10;
				result.push_back(sum % 10);
				K /= 10;
				i--;
			}
			reverse(result.begin(), result.end());
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(addToArrayForm({ 9,9,9,9,9,9,9,9,9,9 }, 1));
		}
	}
}

