#include "stdafx.h"
//Write a function that reverses a string. The input string 
//is given as an array of characters char[].
//
//Do not allocate extra space for another array, you must do this
//by modifying the input array in-place with O(1) extra memory.
//
//You may assume all the characters consist of printable ascii characters.
//
//Example 1:
//Input: ["h","e","l","l","o"]
//Output: ["o","l","l","e","h"]
//Example 2:
//
//Input: ["H","a","n","n","a","h"]
//Output: ["h","a","n","n","a","H"]
namespace Solution2019
{
	namespace ReverseString
	{
		void reverseString(vector<char>& s) {
			int start = 0;
			int end = s.size() - 1;
			while (start < end) {
				swap(s[start], s[end]);
				start++;
				end--;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

