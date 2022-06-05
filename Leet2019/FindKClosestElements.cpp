#include "stdafx.h"

//Given a sorted array, two integers k and x, find the k closest elements to x in
//the array. The result should also be sorted in ascending order. If there is a
//tie, the smaller elements are always preferred.
//
//Example 1:
//Input: [1,2,3,4,5], k=4, x=3
//Output: [1,2,3,4]
//
//Example 2:
//Input: [1,2,3,4,5], k=4, x=-1
//Output: [1,2,3,4]
//
//Note:
//The value k is positive and will always be smaller than the length of the
//sorted array.
//Length of the given array is positive and will not exceed 104
//Absolute value of elements in the array and x will not exceed 104

namespace Solution2019
{
	namespace FindKClosestElements
	{
		vector<int> findClosestElements(vector<int>& arr, int k, int x) {
			int len = arr.size();
			int start = 0;
			int end = len - k;
			while (start < end) {
				int mid = start + (end - start) / 2;
				if (x - arr[mid] > arr[mid + k] - x) {
					start = mid + 1;
				}
				else {
					end = mid;
				}
			}
			return vector<int>(arr.begin() + start, arr.begin() + start + k);
		}

		namespace NotAsFast {
			vector<int> findClosestElements(vector<int>& arr, int k, int x) {
				vector<int> result;
				int len = arr.size();
				if (len == 0) { return result; }

				int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
				int l = pos - 1;
				int r = pos;
				while (result.size() < k) {
					int disL = INT_MAX;
					int disR = INT_MAX;
					if (l >= 0) { disL = abs(arr[l] - x); }
					if (r < len) { disR = abs(arr[r] - x); }
					if (disL <= disR) { result.insert(result.begin(), arr[l]); l--; }
					else { result.push_back(arr[r]); r++; }
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

