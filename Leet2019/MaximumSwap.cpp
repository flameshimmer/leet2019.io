#include "stdafx.h"
//Given a non-negative integer, you could swap two digits at 
//most once to get the maximum valued number. 
//Return the maximum valued number you could get.
//
//Example 1:
//Input: 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
//
//Example 2:
//Input: 9973
//Output: 9973
//Explanation: No swap.
//Note:
//The given number is in the range [0, 108]

namespace Solution2019
{
	namespace MaximumSwap
	{
		int maximumSwap(int num) {
			string s = to_string(num);
			int len = s.size();
			int map[10] = { 0 };
			for (int i = 0; i < len; i++) {
				map[s[i] - '0'] = i;
			}

			for (int i = 0; i < len; i++) {
				for (int j = 9; j > s[i] - '0'; j--) {
					if (map[j] > i) {
						swap(s[i], s[map[j]]);
						return stoi(s);
					}
				}
			}
			return num;
		}

		int maximumSwapAnother(int num) {
			string s = to_string(num);
			int len = s.size();
			int maxIndex = len - 1;
			char maxVal = s[len - 1];
			int leftIndex = -1;
			int rightIndex = -1;

			for (int i = len - 2; i >= 0; i--) {
				if (s[i] > maxVal) {
					maxVal = s[i];
					maxIndex = i;
				}
				else if (s[i] < maxVal) {
					leftIndex = i;
					rightIndex = maxIndex;
				}
			}
			if (leftIndex == -1) { return num; }

			swap(s[leftIndex], s[rightIndex]);
			return stoi(s);
		}
		
		void Main() {
			print(maximumSwap(98368));
		}
	}
}

