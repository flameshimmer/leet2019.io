#include "stdafx.h"
#include <queue> 
//Median is the middle value in an ordered integer list. If the size of the 
//list is even, there is no middle value. So the median is the mean of the 
//two middle value.
//
//For example,
//[2,3,4], the median is 3
//[2,3], the median is (2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations:
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
// 
//Example:
//addNum(1)
//addNum(2)
//findMedian() -> 1.5
//addNum(3) 
//findMedian() -> 2
// 
//Follow up:
//If all integer numbers from the stream are between 0 and 100, how would you optimize it?
//If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it? 

namespace Solution2019
{
	//FollowUp answer:
	//1. If all integer numbers from the stream are between 0 and 100, how would you optimize it ?
	//We can maintain an integer array of length 100 to store the count of each number
	//along with a total count.Then, we can iterate over the array to find the middle value to get our median.
	//Time and space complexity would be O(100) = O(1).
	//
	//2. If 99 % of all integer numbers from the stream are between 0 and 100, how would you optimize it ?
	//In this case, we need an integer array of length 100 and a hashmap for these numbers that are not in[0, 100].

	namespace FindMedianfromDataStream
	{
		class MedianFinder {
		private:
			priority_queue<long long> smallerHalf;
			priority_queue<long long> largerHalf;
		public:
			/** initialize your data structure here. */
			MedianFinder() {
			}

			void addNum(int num) {
				smallerHalf.push(num);
				largerHalf.push(-smallerHalf.top());
				smallerHalf.pop();
				if (smallerHalf.size() < largerHalf.size()) {
					smallerHalf.push(-largerHalf.top());
					largerHalf.pop();
				}
			}

			double findMedian() {
				return smallerHalf.size() > largerHalf.size()
					? smallerHalf.top()
					: (smallerHalf.top() - largerHalf.top()) / 2.0;
			}
		};

		/**
		 * Your MedianFinder object will be instantiated and called as such:
		 * MedianFinder* obj = new MedianFinder();
		 * obj->addNum(num);
		 * double param_2 = obj->findMedian();
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

