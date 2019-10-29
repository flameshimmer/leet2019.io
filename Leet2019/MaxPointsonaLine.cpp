#include "stdafx.h"
//Given n points on a 2D plane, find the maximum number of points that
//lie on the same straight line.
//
//Example 1:
//
//Input: [[1,1],[2,2],[3,3]]
//Output: 3
//Explanation:
//^
//|
//|        o
//|     o
//|  o  
//+------------->
//0  1  2  3  4
//Example 2:
//
//Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
//Explanation:
//^
//|
//|  o
//|     o        o
//|        o
//|  o        o
//+------------------->
//0  1  2  3  4  5  6
//NOTE: input types have been changed on April 15, 2019. Please reset to
//default code definition to get new method signature.

namespace Solution2019
{
	namespace MaxPointsonaLine
	{
		namespace UseStringAsHashKey {
			int GCD(int y, int x) {
				if (x == 0) { return y; }
				return GCD(x, y % x);
			}
			int maxPoints(vector<vector<int>>& points) {
				int len = points.size();
				if (len < 2) { return len; }

				int result = 0;
				int x, y, gcd;
				string key;
				for (int i = 0; i < len; i++) {
					vector<int> cur = points[i];
					int dupe = 1;
					int verCount = 0;
					int maxNonVerCount = 0;
					unordered_map<string, int> map;
					for (int j = i + 1; j < len; j++) {
						vector<int> next = points[j];
						if (cur[0] == next[0] && cur[1] == next[1]) {
							dupe++;
						}
						else if (cur[0] == next[0]) { verCount++; }
						else {
							y = next[1] - cur[1];
							x = next[0] - cur[0];
							gcd = GCD(y, x);
							key = to_string(y / gcd) + "_" + to_string(x / gcd);
							map[key]++;
							maxNonVerCount = max(maxNonVerCount, map[key]);
						}
					}
					int curResult = max(verCount, maxNonVerCount) + dupe;
					result = max(result, curResult);
				}
				return result;
			}
		}

		namespace UseDoubleAsHashKey {//---> be careful of precision of double if choosing this method. 
			int maxPoints(vector<vector<int>>& points) {
				int len = points.size();
				if (len < 2) { return len; }

				int result = 0;
				for (int i = 0; i < len; i++) {
					int dupe = 1;
					vector<int> cur = points[i];
					unordered_map<double, int> map; // slope, count
					int verCount = 0;
					int maxNonVer = 0;
					for (int j = i + 1; j < len; j++) {
						vector<int> next = points[j];
						if (cur[0] == next[0] && cur[1] == next[1]) { dupe++; }
						else if (cur[0] == next[0]) { verCount++; }
						else {
							//Due the division of double type has only 16 decimals, the last test case will fail. 
							//A simple to solve these problem is to times a larger value such like 100 or 10000000000000.0.
							double slope = 100.0 * (double)(next[1] - cur[1]) / (double)(next[0] - cur[0]);
							map[slope] ++;
							maxNonVer = max(maxNonVer, map[slope]);
						}
					}
					int curResult = max(verCount, maxNonVer) + dupe;
					result = max(result, curResult);
				}
				return result;
			}
		}
		void Main() {
			vector<vector<int>> test = { {0,0},{94911151,94911150},{94911152,94911151} };
			print(UseDoubleAsHashKey::maxPoints(test));
		}
	}
}

