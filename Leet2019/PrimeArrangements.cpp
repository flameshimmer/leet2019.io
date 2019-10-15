#include "stdafx.h"
//Return the number of permutations of 1 to n so that prime
//numbers are at prime indices (1-indexed.)
//
//(Recall that an integer is prime if and only if it is greater
//than 1, and cannot be written as a product of two positive 
//integers both smaller than it.)
//
//Since the answer may be large, return the answer modulo 10^9 + 7.
//
//Example 1:
//Input: n = 5
//Output: 12
//Explanation: For example [1,2,5,4,3] is a valid permutation, 
//but [5,2,3,4,1] is not because the prime number 5 is at index 1.
//
//Example 2:
//Input: n = 100
//Output: 682289015
// 
//Constraints:
//1 <= n <= 100

namespace Solution2019
{
	namespace PrimeArrangements
	{
		int numPrimeArrangements(int n) {
			vector<bool> prime(n + 1, true);
			int count = 0;

			for (int i = 2; i <= n; i++) {
				if (prime[i]) {
					count++;
					for (int j = i + i; j <= n; j += i) { prime[j] = false; }
				}
			}

			long long result = 1;
			long long mod = 1e9 + 7;
			for (int i = 1; i <= count; i++) {
				result = result * i % mod;
			}
			for (int i = 1; i <= n - count; i++) {
				result = result * i % mod;
			}
			return result % mod;
		}

		namespace NotAsFast {
			bool isPrime(int n) {
				for (int i = 2; i * i <= n; i++) {
					if (n % i == 0) { return false; }
				}
				return true;
			}

			int numPrimeArrangements(int n) {
				int primeCount = 1;
				for (int i = 3; i <= n; i++) {
					if (isPrime(i)) { primeCount++; }
				}

				long long result = 1;
				long long mod = 1e9 + 7;
				for (int i = 1; i <= primeCount; i++) {
					result = result * i % mod;
				}
				for (int i = 1; i <= n - primeCount; i++) {
					result = result * i % mod;
				}
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

