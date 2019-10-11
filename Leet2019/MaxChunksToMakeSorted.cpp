#include "stdafx.h"
#include <numeric>
//Given an array arr that is a permutation of[0, 1, ..., arr.length - 1], 
//we split the array into some number of "chunks" (partitions), and individually
//sort each chunk.After concatenating them, the result equals the sorted array.
//
//What is the most number of chunks we could have made ?
//Example 1 :
//Input : arr = [4, 3, 2, 1, 0]
//Output : 1
//Explanation :
//Splitting into two or more chunks will not return the required result.
//For example, splitting into[4, 3], [2, 1, 0] will result in[3, 4, 0, 1, 2], which isn't sorted.
//
//Example 2 :
//Input : arr = [1, 0, 2, 3, 4]
//Output : 4
//Explanation :
//We can split into two chunks, such as[1, 0], [2, 3, 4].
//However, splitting into[1, 0], [2], [3], [4] is the highest number of chunks possible.
//
//Note :
//arr will have length in range[1, 10].
//arr[i] will be a permutation of[0, 1, ..., arr.length - 1].

namespace Solution2019
{
	namespace MaxChunksToMakeSorted
	{
		int maxChunksToSorted(vector<int>& arr) {
			vector<int> indexArray(arr.size());
			iota(indexArray.begin(), indexArray.end(), 0);
			auto comp = [&arr](int& i1, int& i2) {
				return arr[i1] == arr[i2] ? i1 < i2 : arr[i1] < arr[i2];
			};
			sort(indexArray.begin(), indexArray.end(), comp);

			int maxV = 0;
			int result = 0;
			for (int i = 0; i < indexArray.size(); i++) {
				maxV = max(maxV, indexArray[i]);
				if (maxV == i) { result++; }
			}
			return result;
		}
		
		int maxChunksToSortedAnother(vector<int>& arr) {
			int result = 0;
			int maxV = 0;
			for (int i = 0; i < arr.size(); i++) {
				maxV = max(maxV, arr[i]);
				if (maxV == i) { result++; }
			}
			return result;
		}

		int maxChunksToSortedAnother2(vector<int>& arr) {
			int len = arr.size();
			vector<int> maxOfLeft(len, 0);
			vector<int> minOfRight(len, 0);

			maxOfLeft[0] = arr[0];
			for (int i = 1; i < len; i++) {
				maxOfLeft[i] = max(maxOfLeft[i - 1], arr[i]);
			}

			minOfRight[len - 1] = arr[len - 1];
			for (int i = len - 2; i >= 0; i--) {
				minOfRight[i] = min(minOfRight[i + 1], arr[i]);
			}

			int result = 0;
			for (int i = 0; i < len - 1; i++) {
				if (maxOfLeft[i] <= minOfRight[i + 1]) { result++; }
			}
			return result + 1;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

