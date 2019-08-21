#include "stdafx.h"

//Determine whether an integer is a palindrome.
//An integer is a palindrome when it reads the same backward as forward.
//
//Example 1:
//Input: 121
//Output: true
//
//Example 2 :
//Input: -121
//Output: false
//Explanation: From left to right, it reads - 121. From right to left, it becomes 121 - .
//				Therefore it is not a palindrome.
//
//Example 3:
//Input: 10
//Output: false
//Explanation: Reads 01 from right to left.Therefore it is not a palindrome.
//
//Follow up: Coud you solve it without converting the integer to a string?

namespace Solution2019
{
	namespace PalindromeNumber
	{
		bool PalindromeNumberConvertToString(int num){
			string str = to_string(num);
			int len = str.size();
			if (len < 2) { return true; }

			int start = 0; int end = len - 1;
			while (start < end) {
				if (str[start] != str[end]) { return false; }
				start++;
				end--;
			}
			return true;
		}

		bool PalindromeNumber(int num) {
			if (num < 0) { return false; }
			if (num < 10) { return true; }
			long long div = 1;
			while (num / div > 0) { div *= 10; }
			div /= 10; // remember to back track 1

			while (num > 0) {
				if (num / div != num % 10) { return false; } 
				num = num % div / 10; // %div will get rid of high digit, /div will get rid of low digit
				div /= 100;   // Make sure div is divided by 100, not 10!
			}
			return true;
		}

		void Main() {			
			print(PalindromeNumber(1000021));
			print(PalindromeNumber(1001));
			print(PalindromeNumber(121));
			print(PalindromeNumber(-121));
			print(PalindromeNumber(10));
		}
	}
}

