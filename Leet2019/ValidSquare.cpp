#include "stdafx.h"

//Given the coordinates of four points in 2D space, return whether the four
//points could construct a square.
//The coordinate (x,y) of a point is represented by an integer array with two
//integers.
//
//Example:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//Output: True
// 
//
//Note:
//All the input integers are in the range [-10000, 10000].
//A valid square has four equal sides with positive length and four equal angles
//(90-degree angles).
//Input points have no order. 

namespace Solution2019
{
	namespace ValidSquare
	{
		int getDistance(vector<int>& p1, vector<int>& p2) {
			return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
		}

		bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
			map<int, int> dmap;
			dmap[getDistance(p1, p2)]++;
			dmap[getDistance(p1, p3)]++;
			dmap[getDistance(p1, p4)]++;
			dmap[getDistance(p2, p3)]++;
			dmap[getDistance(p2, p4)]++;
			dmap[getDistance(p3, p4)]++;

			if (!dmap.size() == 2) { return false; }

			vector<pair<int, int>> v(dmap.begin(), dmap.end());
			if (v[0].second != 4) { return false; }
			return v[1].first == 2 * v[0].first;
		}

		void Main() {
			vector<vector<int>> test = { {0,0}, {1,1}, {1,0}, {0,1} };
			print(validSquare(test[0], test[1], test[2], test[3]));
		}
	}
}

