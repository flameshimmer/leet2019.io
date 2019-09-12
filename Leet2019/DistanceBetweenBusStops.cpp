#include "stdafx.h"
//A bus has n stops numbered from 0 to n - 1 that form a circle. 
//We know the distance between all pairs of neighboring stops 
//where distance[i] is the distance between the stops number 
//i and (i + 1) % n.
//
//The bus goes along both directions i.e. clockwise and counterclockwise.
//
//Return the shortest distance between the given start and 
//destination stops.
//
//Example 1:
//Input: distance = [1,2,3,4], start = 0, destination = 1
//Output: 1
//Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.
//
//Example 2:
//Input: distance = [1,2,3,4], start = 0, destination = 2
//Output: 3
//Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
//
//Example 3:
//Input: distance = [1,2,3,4], start = 0, destination = 3
//Output: 4
//Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
//
//Constraints:
//1 <= n <= 10^4
//distance.length == n
//0 <= start, destination < n
//0 <= distance[i] <= 10^4 

namespace Solution2019
{
	namespace DistanceBetweenBusStops
	{
		int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
			if (destination < start) { swap(start, destination); }
			int direct = 0;
			int indirect = 0;
			for (int i = 0; i < distance.size(); i++) {
				if (i >= start && i < destination) { direct += distance[i]; }
				else { indirect += distance[i]; }
			}
			return min(direct, indirect);
		}

		int distanceBetweenBusStopsAnother(vector<int>& distance, int start, int destination) {
			vector<int> sum;
			int cur = 0;
			sum.push_back(0);
			for (int i : distance) {
				cur += i;
				sum.push_back(cur);
			}

			if (destination < start) { int tmp = start; start = destination; destination = tmp; }

			int direct = sum[destination] - sum[start];
			int indirect = sum[start] + sum[sum.size() - 1] - sum[destination];
			return min(direct, indirect);
		}
		void Main() {
			vector<int> A = { 1, 2, 3, 4 };
			print(distanceBetweenBusStops(A, 0, 1));
			print(distanceBetweenBusStops(A, 0, 2));
			print(distanceBetweenBusStops(A, 0, 3));
		}
	}
}

