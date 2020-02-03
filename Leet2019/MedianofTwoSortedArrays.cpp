#include "stdafx.h"
//
//There are two sorted arrays nums1 and nums2 of size len1 and len2 respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(len1 + len2)).
//
//You may assume nums1 and nums2 cannot be both empty.
//
//Example 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is(2 + 3) / 2 = 2.5

namespace Solution2019
{
	namespace MedianofTwoSortedArrays
	{
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int n1 = nums1.size();
			int n2 = nums2.size();
			if (n1 > n2) { return findMedianSortedArrays(nums2, nums1); }

			int k = (n1 + n2 + 1) / 2;

			int l = 0;
			int r = n1;
			while (l < r) {
				int m1 = l + (r - l) / 2;
				int m2 = k - m1;
				if (nums1[m1] < nums2[m2 - 1]) {
					l = m1 + 1;
				}
				else {
					r = m1;
				}
			}

			int m1 = l;
			int m2 = k - l;
			int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
				m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
			if ((n1 + n2) % 2 == 1) { return c1; }

			int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1],
				m2 >= n2 ? INT_MAX : nums2[m2]);
			return (c1 + c2) * 0.5;
		}

		void Main() {
			print(findMedianSortedArrays(createVector({ 1, 2 }), createVector({ 3, 4 })));
		}
	}
}

