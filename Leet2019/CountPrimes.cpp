#include "stdafx.h"

//Count the number of prime numbers less than a non-negative number, n.
//
//Example:
//Input: 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

namespace Solution2019
{
	namespace CountPrimes
	{
		int countPrimes(int n) {
			if (n < 2) { return 0; }

			vector<bool> notPrime(n, false);
			notPrime[0] = true;
			notPrime[1] = true;

			// note that sqrt(n) is a double!!! so can't cast into int to use it. 
			for (int i = 2; i < sqrt(n); i++) {
				if (!notPrime[i]) {
					for (int j = 2; i * j < n; j++) {
						notPrime[i * j] = true;
					}
				}
			}

			int result = 0;
			for (int i = 2; i < notPrime.size(); i++) {
				if (!notPrime[i]) { result++; }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

