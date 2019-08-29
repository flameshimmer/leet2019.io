#include "stdafx.h"
//You are climbing a stair case. It takes n steps to reach to the top.
//Each time you can either climb 1 or 2 steps. 
//In how many distinct ways can you climb to the top?
//Note: Given n will be a positive integer.
//
//Example 1:
//Input: 2
//Output: 2
//Explanation: There are two ways to climb to the top.
//1. 1 step + 1 step
//2. 2 steps
//
//Example 2:
//Input: 3
//Output: 3
//Explanation: There are three ways to climb to the top.
//1. 1 step + 1 step + 1 step
//2. 1 step + 2 steps
//3. 2 steps + 1 step

namespace Solution2019
{
	namespace ClimbingStairs
	{
		int ClimbingStairsTooSlow(int n) {
			if (n < 2) { return 1; }
			int result = ClimbingStairsTooSlow(n - 1);
			result += ClimbingStairsTooSlow(n - 2);
			return result;
		}

		int ClimibingStairsInternal(int n, int* mem) {
			if (n < 2) { return 1; }
			if (mem[n] == -1) {
				mem[n] = ClimibingStairsInternal(n - 1, mem) + ClimibingStairsInternal(n - 2, mem);
			}
			return mem[n];
		}

		int ClimbingStairsRecursionWithMemTable(int n) {
			if (n < 2) { return 1; }
			int* mem = new int[n+1];
			memset(mem, -1, sizeof(int) * (n+1));
			mem[0] = 1;
			mem[1] = 1;
			return ClimibingStairsInternal(n, mem);
		}

		// Dp way. 
		int ClimbingStairs(int n) {
			if (n < 2) { return 1; }
			int* mem = new int[n + 1];
			mem[1] = 1;
			mem[2] = 2;
			for (int i = 3; i <= n; i++) {
				mem[i] = mem[i - 1] + mem[i - 2];
			}
			return mem[n];
		}

		void Main() {
			print(ClimbingStairs(44));
			print(ClimbingStairs(2));
			print(ClimbingStairs(3));
		}
	}
}

