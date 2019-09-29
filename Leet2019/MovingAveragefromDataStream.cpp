#include "stdafx.h"
//Given a stream of integersand a window size, calculate
//the moving average of all integers in the sliding window.
//
//Example:
//
//MovingAverage m = new MovingAverage(3);
//m.next(1) = 1
//m.next(10) = (1 + 10) / 2
//m.next(3) = (1 + 10 + 3) / 3
//m.next(5) = (10 + 3 + 5) / 3

namespace Solution2019
{
	namespace MovingAveragefromDataStream
	{

		class MovingAverage {
		private:
			int maxSize;
			queue<int> q;
			int sum;
		public:
			/** Initialize your data structure here. */
			MovingAverage(int size) {
				maxSize = size;
				sum = 0;
			}

			double next(int val) {
				sum += val;
				q.push(val);
				if (q.size() > maxSize) {
					sum -= q.front();
					q.pop();
				}
				return double(sum) / double(q.size());
			}
		};
	
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

