#include "stdafx.h"
//A string of '0's and '1's is monotone increasing if it consists 
//of some number of '0's (possibly 0), followed by some number 
//of '1's (also possibly 0.)
//
//We are given a string S of '0's and '1's, and we may flip 
//any '0' to a '1' or a '1' to a '0'.
//
//Return the minimum number of flips to make S monotone increasing.
//
//Example 1:
//Input: "00110"
//Output: 1
//Explanation: We flip the last digit to get 00111.
//
//Example 2:
//Input: "010110"
//Output: 2
//Explanation: We flip to get 011111, or alternatively 000111.
//
//Example 3:
//Input: "00011000"
//Output: 2
//Explanation: We flip to get 00000000.

//Note:
//1 <= S.length <= 20000
//S only consists of '0' and '1' characters.

namespace Solution2019
{
	namespace FlipStringtoMonotoneIncreasing
	{
		int minFlipsMonoIncr(string S) {
			int len = S.size();
			vector<int> L(len + 1);
			vector<int> R(len + 1);
			for (int i = 1, j = len-1; i<=len; i++, j--) {
				L[i] = L[i - 1] + (S[i-1] == '0' ? 0 : 1);
				R[j] = R[j + 1] + (S[j] == '1' ? 0 : 1);
			}
			
			int result = INT_MAX;
			for (int i = 0; i <= len; i++) {
				result = min(result, L[i] + R[i]);
			}
			return result;
		}
		void Main() {			
			print(minFlipsMonoIncr("00110"));
		}
	}
}

