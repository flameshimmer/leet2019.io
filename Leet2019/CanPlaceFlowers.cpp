#include "stdafx.h"
//Suppose you have a long flowerbed in which some of 
//the plots are planted and some are not. However, flowers 
//cannot be planted in adjacent plots - they would compete 
//for water and both would die.
//
//Given a flowerbed (represented as an array containing 0 and 1,
//where 0 means empty and 1 means not empty), and a number n, 
//return if n new flowers can be planted in it without violating
//the no-adjacent-flowers rule.
//
//Example 1:
//Input: flowerbed = [1,0,0,0,1], n = 1
//Output: True
//
//Example 2:
//Input: flowerbed = [1,0,0,0,1], n = 2
//Output: False
//Note:
//The input array won't violate no-adjacent-flowers rule.
//The input array size is in the range of [1, 20000].
//n is a non-negative integer which won't exceed the input array size. 

namespace Solution2019
{
	namespace CanPlaceFlowers
	{
		bool canPlaceFlowers(vector<int>& flowerbed, int n) {
			int len = flowerbed.size();

			for (int i = 0; i < len; i++) {
				if ((i == 0 || flowerbed[i - 1] == 0) && flowerbed[i] == 0 && (i == len - 1 || flowerbed[i + 1] == 0)) {
					n--;
					flowerbed[i] = 1;
				}
			}
			return n <= 0;
		}

		bool canPlaceFlowersAnother(vector<int>& flowerbed, int n) {
			flowerbed.insert(flowerbed.begin(), 0);
			flowerbed.push_back(0);
			int len = flowerbed.size();
			int start = 0;
			int end = 0;
			while (end < len) {
				while (end < len && flowerbed[end] == 1) { end++; }
				if (end == len) { break; }
				start = end;
				while (end < len && flowerbed[end] == 0) { end++; }
				n -= (end - start - 1) / 2;
			}
			return n <= 0;
		}

		void Main() {
			vector<int> test = { 1,0,0,0,1 };
			print(canPlaceFlowers(test, 1));
		}
	}
}

