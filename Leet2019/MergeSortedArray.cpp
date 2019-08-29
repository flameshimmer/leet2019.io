#include "stdafx.h"
//Given two sorted integer arrays nums1 and nums2, 
//merge nums2 into nums1 as one sorted array.
//
//Note:
//
//The number of elements initialized in nums1 and nums2 are m and n respectively.
//You may assume that nums1 has enough space (size that is greater or equal to m + n)
//to hold additional elements from nums2.
//
//Example:
//Input:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//Output: [1,2,2,3,5,6]

namespace Solution2019
{
	namespace MergeSortedArray
	{
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			if (n == 0) { return; }			

			int i = m+n-1;
			int j = m - 1;
			int k = n-1;
			while (k >= 0) {
				bool ary1Larger = (j>=0?nums1[j]:INT_MIN) > nums2[k]; //----> note that j might go below 0 in this case!!!
				nums1[i] = ary1Larger ? nums1[j] : nums2[k];
				if (ary1Larger) { j--; }
				else{ k--; }
				i--;
			}
			return;
		}

		void Main() {
			string test = "tst test test";
			vector<int> nums1 = { 0 };
			vector<int> nums2 = { 1 };
			
	
			merge(nums1, 0, nums2, 1);
			print(nums1);
		}
	}
}

