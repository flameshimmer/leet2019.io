#include "stdafx.h"
//Given m arrays, and each array is sorted in ascending order. 
//Now you can pick up two integers from two different arrays 
//(each array picks one) and calculate the distance. We define 
//the distance between two integers a and b to be their absolute 
//difference |a-b|. Your task is to find the maximum distance.
//
//Example 1:
//Input: 
//[[1,2,3],
// [4,5],
// [1,2,3]]
//Output: 4
//Explanation: 
//One way to reach the maximum distance 4 is to pick 1 in the 
//first or third array and pick 5 in the second array.
//Note:
//Each given array will have at least 1 number. There will be at least two non-empty arrays.
//The total number of the integers in all the m arrays will be in the range of [2, 10000].
//The integers in the m arrays will be in the range of [-10000, 10000]. 

namespace Solution2019
{
	namespace MaximumDistanceinArrays
	{
		int maxDistance(vector<vector<int>>& arrays) {
			int left = arrays[0].front();
			int right = arrays[0].back();
			int result = 0;
			for (int i = 1; i < arrays.size(); i++) {
				vector<int> a = arrays[i];
				result = max(result, max(right - a.front(), a.back() - left));
				left = min(left, a.front());
				right = max(right, a.back());
			}
			return result;
		}


		int maxDistanceAnother(vector<vector<int>>& arrays) {
			int min1 = INT_MAX;
			int min2 = INT_MAX;
			int max1 = INT_MIN;
			int max2 = INT_MIN;
			int imin1 = -1;
			int imin2 = -1;
			int imax1 = -1;
			int imax2 = -1;

			for (int i = 0; i < arrays.size(); i++) {
				int vmin = arrays[i][0];
				if (vmin < min1) { 
					min2 = min1; 
					imin2 = imin1;
					min1 = vmin;
					imin1 = i;
				}
				else if (vmin < min2) {
					min2 = vmin;
					imin2 = i;
				}
				int vmax = arrays[i][arrays[i].size() - 1];
				if (vmax > max1) {
					max2 = max1;
					imax2 = imax1;
					max1 = vmax;
					imax1 = i;
				}
				else if (vmax > max2) {
					max2 = vmax;
					imax2 = i;
				}
			}

			int result = 0;
			if (imin1 != imax1) { result = max1 - min1; }
			else {
				result = max(max1 - min2, max2 - min1);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

