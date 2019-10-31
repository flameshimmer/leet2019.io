#include "stdafx.h"

//Given an array w of positive integers, where w[i] describes the weight of index
//i, write a function pickIndex which randomly picks an index in proportion to
//its weight.
//
//Note:
//1 <= w.length <= 10000
//1 <= w[i] <= 10^5
//pickIndex will be called at most 10000 times.
//
//Example 1:
//Input: 
//["Solution","pickIndex"]
//[[[1]],[]]
//Output: [null,0]
//
//Example 2:
//Input: 
//["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
//[[[1,3]],[],[],[],[],[]]
//Output: [null,0,1,1,1,0]
//Explanation of Input Syntax:
//The input is two lists: the subroutines called and their arguments. Solution's
//constructor has one argument, the array w. pickIndex has no arguments.
//Arguments are always wrapped with a list, even if there aren't any.

namespace Solution2019
{
	namespace RandomPickwithWeight
	{
		class Solution {
			vector<int> range;
		public:
			Solution(vector<int>& w) {
				for (int v : w) {
					range.push_back(range.empty() ? v : range.back() + v);
				}
			}

			int pickIndex() {
				int index = rand() % range.back();
				auto it = upper_bound(range.begin(), range.end(), index);
				return it - range.begin();
			}
		};

		namespace Another {
			class Solution {
				vector<int> range;
				int maxV;
			public:
				Solution(vector<int>& w) {
					maxV = 0;
					range.push_back(0);
					for (int v : w) {
						range.push_back(range.back() + v);
					}
					maxV = range.back();
				}

				int pickIndex() {
					int index = rand() % maxV;
					auto it = upper_bound(range.begin(), range.end(), index);
					return prev(it) - range.begin();
				}
			};
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

