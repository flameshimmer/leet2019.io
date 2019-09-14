#include "stdafx.h"
//Given an integer array, find three numbers whose 
//product is maximum and output the maximum product.
//
//Example 1:
//Input: [1,2,3]
//Output: 6
// 
//Example 2:
//Input: [1,2,3,4]
//Output: 24
//
//Note:
//The length of the given array will be in range [3,104] 
//and all elements are in the range [-1000, 1000].
//Multiplication of any three numbers in the input won't 
//exceed the range of 32-bit signed integer.

namespace Solution2019
{
	namespace MaximumProductofThreeNumbers
	{
		int MaximumProductofThreeNumbers(vector<int> A) {
			int max1 = INT_MIN;
			int max2 = INT_MIN;
			int max3 = INT_MIN;
			int min1 = INT_MAX;
			int min2 = INT_MAX;

			for (int i : A) {
				if (i > max1) {					
					max3 = max2;
					max2 = max1;
					max1 = i;					
				} else if (i > max2) {
					max3 = max2;
					max2 = i;
				}
				else if (i > max3) { max3 = i; }

				if (i < min1) { //// Note this should be if, not else if here!!!!
					min2 = min1;
					min1 = i;
				}
				else if (i < min2) { min2 = i; }				
			}
			return max(max1 * max2 * max3, min1 * min2 * max1);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

