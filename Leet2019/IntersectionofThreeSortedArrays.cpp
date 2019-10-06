#include "stdafx.h"
//Given three integer arrays arr1, arr2 and arr3 sorted in 
//strictly increasing order, return a sorted array of only 
//the integers that appeared in all three arrays.
//
//Example 1:
//Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
//Output: [1,5]
//Explanation: Only 1 and 5 appeared in the three arrays.
//
//Constraints:
//1 <= arr1.length, arr2.length, arr3.length <= 1000
//1 <= arr1[i], arr2[i], arr3[i] <= 2000

namespace Solution2019
{
	namespace IntersectionofThreeSortedArrays
	{
		vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
			vector<int> result;
			int len1 = arr1.size();
			int len2 = arr2.size();
			int len3 = arr3.size();
			int i1 = 0;
			int i2 = 0;
			int i3 = 0;

			while (i1 < len1 && i2 < len2 && i3 < len3) {
				int v1 = arr1[i1];
				int v2 = arr2[i2];
				int v3 = arr3[i3];
				if (v1 == v2 && v2 == v3) {
					result.push_back(v1);
					i1++;
					i2++;
					i3++;
				}
				else if (v1 < v2) { i1++; }
				else if (v2 < v3) { i2++; }
				else { i3++; }
			}
			return result;
		}
		void Main() {
			vector<int> a1 = { 1,2,3,4,5 };
			vector<int> a2 = { 1,2,5,7,9 };
			vector<int> a3 = { 1,3,4,5,8 };
			print(arraysIntersection(a1, a2, a3));
		}
	}
}

