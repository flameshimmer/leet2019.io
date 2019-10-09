#include "stdafx.h"
//Given n non-negative integers representing an elevation 
//map where the width of each bar is 1, compute how much 
//water it is able to trap after raining.
//
//
//The above elevation map is represented by array 
//[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain
//water (blue section) are being trapped. Thanks Marcos for
//contributing this image!
//
//Example:
//Input: [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6

namespace Solution2019
{
	namespace TrappingRainWater
	{
		int trapOnePass(vector<int>& height) {
			int len = height.size();
			int l = 0;
			int r = len - 1;
			int result = 0;

			while (l < r) {
				int minV = min(height[l], height[r]);
				if (minV == height[l]) {
					l++;
					while (height[l] < minV) {
						result += minV - height[l];
						l++;
					}
				}
				else {
					r--;
					while (height[r] < minV) {
						result += minV - height[r];
						r--;
					}
				}
			}
			return result;
		}
		int trapTwoPass(vector<int>& height) {
			int len = height.size();
			if (len < 2) { return 0; }

			vector<int> leftMax(len, 0);
			vector<int> rightMax(len, 0);
			int curLeftMax = 0;
			int curRightMax = 0;
			for (int i = 0; i < len; i++) {
				leftMax[i] = curLeftMax;
				curLeftMax = max(curLeftMax, height[i]);

				rightMax[len - 1 - i] = curRightMax;
				curRightMax = max(curRightMax, height[len - 1 - i]);
			}

			int result = 0;
			for (int i = 0; i < len; i++) {
				result += max(0, min(leftMax[i], rightMax[i]) - height[i]);
			}
			return result;
		}



		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

