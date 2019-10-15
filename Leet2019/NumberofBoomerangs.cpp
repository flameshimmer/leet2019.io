#include "stdafx.h"
//Given n points in the plane that are all pairwise distinct,
//a "boomerang" is a tuple of points (i, j, k) such that the 
//distance between i and j equals the distance between i and 
//k (the order of the tuple matters).
//
//Find the number of boomerangs. You may assume that n will 
//be at most 500 and coordinates of points are all in the 
//range [-10000, 10000] (inclusive).
//
//Example:
//Input:
//[[0,0],[1,0],[2,0]]
//Output:
//2
//
//Explanation:
//The two boomerangs are [[1,0],[0,0],[2,0]] 
//and [[1,0],[2,0],[0,0]]
namespace Solution2019
{
	namespace NumberofBoomerangs
	{
		int getDistance(vector<int>& a, vector<int>& b) {
			int x = a[0] - b[0];
			int y = a[1] - b[1];
			return x * x + y * y;
		}

		int numberOfBoomerangs(vector<vector<int>>& points) {
			int len = points.size();

			int result = 0;
			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) {
				for (int j = 0; j < len; j++) {
					if (i == j) { continue; }
					map[getDistance(points[i], points[j])]++;
				}
				for (auto& p : map) {
					result += p.second * (p.second - 1);
				}
				map.clear();
			}

			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

