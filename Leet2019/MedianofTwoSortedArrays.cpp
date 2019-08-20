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
		const int INF = 2e9;

		double findK(vector<int> & nums1, vector<int> & nums2, int k) {
			int len1 = nums1.size();
			int len2 = nums2.size();
			int lenSum = len1 + len2;
			for (int i = 0; i < 2; i++) {
				int l = -1;
				int r = len1;
				while (l != r - 1) {
					int nums1_index = (l + r) / 2;
					int nums2_index = k - nums1_index - 1;

					int nums2_prev = (nums2_index < 0 ? -INF : (nums2_index >= len2 ? INF : nums2[nums2_index]));
					int nums2_next = (nums2_index < -1 ? -INF : (nums2_index >= len2 - 1 ? INF : nums2[nums2_index + 1]));

					if (nums1[nums1_index] >= nums2_prev && nums1[nums1_index] <= nums2_next) return nums1[nums1_index];
					if (nums1[nums1_index] < nums2_prev) {
						l = nums1_index;
					}
					else {
						r = nums1_index;
					}
				}
				swap(nums1, nums2);  swap(len1, len2);
			}
			return 0;
		}

		double MedianofTwoSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int len1 = nums1.size() + nums2.size();
			if (len1 & 1) {
				return findK(nums1, nums2, len1 / 2);
			}
			else {
				return (findK(nums1, nums2, len1 / 2) + findK(nums1, nums2, len1 / 2 - 1))*0.5;
			}

		}

		void Main() {
			print(MedianofTwoSortedArrays(createVector({ 1, 2 }), createVector({ 3, 4 })));
		}
	}
}

