#include "stdafx.h"
//There are a row of n houses, each house can be painted 
//with one of the three colors: red, blue or green. The 
//cost of painting each house with a certain color is 
//different. You have to paint all the houses such that no
//two adjacent houses have the same color.
//
//The cost of painting each house with a certain color is
//represented by a n x 3 cost matrix. For example,
//costs[0][0] is the cost of painting house 0 with color 
//red; costs[1][2] is the cost of painting house 1 with 
//color green, and so on... Find the minimum cost to paint
//all houses.
//
//Note:
//All costs are positive integers.
//
//Example:
//Input: [[17,2,17],[16,16,5],[14,3,19]]
//Output: 10
//Explanation: Paint house 0 into blue, paint house 1 
//into green, paint house 2 into blue. 
//Minimum cost: 2 + 5 + 3 = 10.

namespace Solution2019
{
	namespace PaintHouse
	{
		int minCost(vector<vector<int>>& costs) {
			int len = costs.size();
			if (len == 0) { return 0; }

			int lastRed = costs[0][0];
			int lastGreen = costs[0][1];
			int lastBlue = costs[0][2];

			for (int i = 1; i < len; i++) {
				int curRed = min(lastGreen, lastBlue) + costs[i][0];
				int curGreen = min(lastRed, lastBlue) + costs[i][1];
				int curBlue = min(lastRed, lastGreen) + costs[i][2];

				lastRed = curRed;
				lastGreen = curGreen;
				lastBlue = curBlue;
			}
			return min(lastRed, min(lastGreen, lastBlue));
		}

		int minCostAnother(vector<vector<int>>& costs) {
			int houseCount = costs.size();
			if (houseCount == 0) { return 0; }

			for (int i = 1; i < houseCount; i++)
			{
				costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
				costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
				costs[i][2] += min(costs[i - 1][0], costs[i - 2][1]);
			}
			return min(costs[houseCount - 1][0], min(costs[houseCount - 1][1], costs[houseCount - 1][2]));
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

