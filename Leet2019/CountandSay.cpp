#include "stdafx.h"
//The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.

namespace Solution2019
{
	namespace CountandSay
	{
		string CountandSay(int n) {
			string input = "1";
			for (int i = 0; i < n - 1; i++) {
				int len = input.size();
				string newInput = "";
				int j = 0;
				while (j < len) {
					int count = 1;
					while (j + 1 < len && input[j] == input[j + 1]) { count++; j++; }
					newInput += to_string(count) + input[j];
					j++;
				}
				input = newInput;
			}
			return input;
		}

		void Main() {
			string test = "tst test test";
			print(CountandSay(1));
			print(CountandSay(2));
			print(CountandSay(3));
			print(CountandSay(4));
			print(CountandSay(5));
		}
	}
}

