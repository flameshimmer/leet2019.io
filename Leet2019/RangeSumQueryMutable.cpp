#include "stdafx.h"

//Given an integer array nums, find the sum of the elements between indices i and
//j (i ≤ j), inclusive.
//The update(i, val) function modifies nums by updating the element at index i to
//val.
//
//Example:
//Given nums = [1, 3, 5]
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//
//Note:
//The array is only modifiable by the update function.
//You may assume the number of calls to update and sumRange function is
//distributed evenly.

namespace Solution2019
{
	namespace RangeSumQueryMutable
	{
		class NumArray {

			class FenwickTree {
			private:
				vector<int> sums;
				int lowbit(int x) { return x & (-x); }

			public:
				FenwickTree(int n) {
					sums.resize(n + 1, 0);
				}

				void update(int i, int delta) {
					while (i < sums.size()) {
						sums[i] += delta;
						i += lowbit(i);
					}
				}

				int query(int i) {
					int result = 0;
					while (i > 0) {
						result += sums[i];
						i -= lowbit(i);
					}
					return result;
				}
			};

			FenwickTree tree;
			vector<int> nums;

		public:
			NumArray(vector<int>& data) : nums(data), tree(data.size()) {
				for (int i = 0; i < nums.size(); i++) {
					tree.update(i + 1, nums[i]);
				}
			}

			void update(int i, int val) {
				tree.update(i + 1, val - nums[i]);
				nums[i] = val;
			}

			int sumRange(int i, int j) {
				return tree.query(j + 1) - tree.query(i);
			}
		};

		/**
		 * Your NumArray object will be instantiated and called as such:
		 * NumArray* obj = new NumArray(nums);
		 * obj->update(i,val);
		 * int param_2 = obj->sumRange(i,j);
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

