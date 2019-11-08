#include "stdafx.h"

//Given n, how many structurally unique BST's (binary search trees) that store
//values 1 ... n?
//
//Example:
//Input: 3
//Output: 5
//Explanation:
//Given n = 3, there are a total of 5 unique BST's:
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3 

namespace Solution2019
{
	namespace UniqueBinarySearchTrees
	{
		namespace RecursionAndMemoryTable {
			int helper(int n, vector<int>& M) {
				if (n < 2) { return 1; }
				if (M[n] != 0) { return M[n]; }
				int result = 0;
				for (int i = 1; i <= n; i++) {
					result += helper(i - 1, M) * helper(n - i, M);
				}
				M[n] = result;
				return result;

			}

			int numTrees(int n) {
				vector<int> M(n + 1, 0);
				return helper(n, M);
			}
		}

		namespace DP {
			int numTrees(int n) {
				vector<int> M(n + 1, 0);
				M[0] = 1;
				M[1] = 1;
				for (int i = 2; i <= n; i++) {
					for (int j = 1; j <= i; j++) {
						M[i] += M[j - 1] * M[i - j];
					}
				}
				return M[n];
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

