#include "stdafx.h"
//Design a hit counter which counts the number of hits received in the past 5 minutes.
//
//Each function accepts a timestamp parameter (in seconds granularity) and you may 
//assume that calls are being made to the system in chronological order 
//(ie, the timestamp is monotonically increasing). 
//You may assume that the earliest timestamp starts at 1.
//
//It is possible that several hits arrive roughly at the same time.
//
//Example:
//
//HitCounter counter = new HitCounter();
//
//// hit at timestamp 1.
//counter.hit(1);
//
//// hit at timestamp 2.
//counter.hit(2);
//
//// hit at timestamp 3.
//counter.hit(3);
//
//// get hits at timestamp 4, should return 3.
//counter.getHits(4);
//
//// hit at timestamp 300.
//counter.hit(300);
//
//// get hits at timestamp 300, should return 4.
//counter.getHits(300);
//
//// get hits at timestamp 301, should return 3.
//counter.getHits(301); 
//
//Follow up:
//What if the number of hits per second could be very large? Does your design scale? 

namespace Solution2019
{
	namespace DesignHitCounter
	{
		namespace UseConstantArray {
			class HitCounter {
			private:
				long long* times;
				int* hits;
			public:
				/** Initialize your data structure here. */
				HitCounter() {
					times = new long long[300];
					hits = new int[300];
				}

				/** Record a hit.
					@param timestamp - The current timestamp (in seconds granularity). */
				void hit(int timestamp) {
					int index = timestamp % 300;
					if (times[index] != timestamp) {
						times[index] = timestamp;
						hits[index] = 1;
					}
					else {
						hits[index] ++;
					}
				}

				/** Return the number of hits in the past 5 minutes.
					@param timestamp - The current timestamp (in seconds granularity). */
				int getHits(int timestamp) {
					int result = 0;
					for (int i = 0; i < 300; i++) {
						if ((long long)timestamp - times[i] < 300) {
							result += hits[i];
						}
					}
					return result;
				}
			};

			/**
			 * Your HitCounter object will be instantiated and called as such:
			 * HitCounter* obj = new HitCounter();
			 * obj->hit(timestamp);
			 * int param_2 = obj->getHits(timestamp);
			 */
		}

		namespace UseHashMap {
			class HitCounter {
				map<int, int> hitset;
				int sum;

				void updateHitset(int t) {
					for (auto p = hitset.begin(); p != hitset.end(); p++) {
						if (t - p->first >= 300) {
							sum -= p->second;
							hitset.erase(p->first);
						}
						else {
							break;
						}
					}
				}

			public:
				/** Initialize your data structure here. */
				HitCounter() {
					sum = 0;
				}

				/** Record a hit.
					@param timestamp - The current timestamp (in seconds granularity). */
				void hit(int timestamp) {
					hitset[timestamp]++;
					sum++;
					updateHitset(timestamp);
				}

				/** Return the number of hits in the past 5 minutes.
					@param timestamp - The current timestamp (in seconds granularity). */
				int getHits(int timestamp) {
					updateHitset(timestamp);
					return sum;
				}
			};

			/**
			 * Your HitCounter object will be instantiated and called as such:
			 * HitCounter* obj = new HitCounter();
			 * obj->hit(timestamp);
			 * int param_2 = obj->getHits(timestamp);
			 */
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

