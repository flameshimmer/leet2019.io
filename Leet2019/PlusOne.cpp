#include "stdafx.h"
//Given a non-empty array of digits representing a 
//non-negative integer, plus one to the integer.
//
//The digits are stored such that the most significant digit
//is at the head of the list, and each element in the array contain a single digit.
//
//You may assume the integer does not contain any leading zero, 
//except the number 0 itself.
//
//Example 1:
//Input: [1,2,3]
//Output: [1,2,4]
//Explanation: The array represents the integer 123.
//
//Example 2:
//Input: [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.

namespace Solution2019
{
	namespace PlusOne
	{
		vector<int> plusOne(vector<int>& digits) {
			int len = digits.size();
			if (len == 0) { return digits; }

			int carry = 0;
			for (int i = len - 1; i >= 0; i--) {
				int sum = digits[i] + carry + (i == len - 1 ? 1 : 0);
				digits[i] = sum % 10;
				carry = sum / 10;
			}
			if (carry > 0) {
				digits.insert(digits.begin(), carry);
			}
			return digits;
		}

		vector<int> plusOneAnotherWay(vector<int>& digits) {
			int len = digits.size();
			if (len == 0) { return digits; }
			
			vector<int> result;
			int carry = 1;
			int i = len - 1;
			while (i >= 0 || carry > 0) {
				int sum = carry + (i >= 0 ? digits[i] : 0);
				result.insert(result.begin(), sum % 10);
				carry = sum / 10;
				i--;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

