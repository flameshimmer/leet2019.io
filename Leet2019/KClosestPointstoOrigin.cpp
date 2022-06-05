#include "stdafx.h"
//We have a list of points on the plane.  
//Find the K closest points to the origin (0, 0).
//
//(Here, the distance between two points on a 
//plane is the Euclidean distance.)
//
//You may return the answer in any order.  
//The answer is guaranteed to be unique 
//(except for the order that it is in.)
//
//Example 1:
//Input: points = [[1,3],[-2,2]], K = 1
//Output: [[-2,2]]
//Explanation: 
//The distance between (1, 3) and the origin is sqrt(10).
//The distance between (-2, 2) and the origin is sqrt(8).
//Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
//We only want the closest K = 1 points from the origin, 
//so the answer is just [[-2,2]].
//
//Example 2:
//Input: points = [[3,3],[5,-1],[-2,4]], K = 2
//Output: [[3,3],[-2,4]]
//(The answer [[-2,4],[3,3]] would also be accepted.)
// 
//Note:
//1 <= K <= points.length <= 10000
//-10000 < points[i][0] < 10000
//-10000 < points[i][1] < 10000

namespace Solution2019
{
	namespace KClosestPointstoOrigin
	{
		vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
			auto comp = [](vector<int>& a, vector<int>& b) {
				return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
			};

			sort(points.begin(), points.end(), comp);
			points.resize(K);
			return points;
		}

		namespace PriorityQueue {

			struct compare {
				bool operator() (vector<int> a, vector<int> b) {
					return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
				}
			};

			vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
				priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
				vector<vector<int>> result;
				for (int i = 0; i < K; i++) {
					result.push_back(pq.top());
					pq.pop();
				}
				return result;
			}

		}

		namespace AnotherPriorityQueue {
			struct Dist {
				int x;
				int y;
				double d;
				Dist(int x, int y) {
					this->x = x;
					this->y = y;
					this->d = sqrt(x * x + y * y);
				}

				bool operator< (const Dist& rhs) const {
					return d < rhs.d;
				}
			};

			vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
				vector<vector<int>> results;
				int len = points.size();
				if (len == 0 || K < 1) { return results; }

				priority_queue<Dist> pq;
				for (vector<int>& p : points) {
					if (pq.size() < K) { pq.push({ p[0], p[1] }); }
					else {
						auto [x, y, d] = pq.top();
						if (d > sqrt(p[0] * p[0] + p[1] * p[1])) {
							pq.pop();
							pq.push({ p[0], p[1] });
						}
					}
				}
				while (!pq.empty()) {
					auto [x, y, d] = pq.top();
					pq.pop();
					results.push_back({ x, y });
				}
				return results;
			}

			vector<vector<int>> kClosestAnother(vector<vector<int>>& points, int K) {
				vector<vector<int>> result;
				int len = points.size();
				if (len == 0 || K == 0) { return result; }

				auto comp = [](const vector<int>& p1, const vector<int>& p2) {
					return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
				};

				priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

				for (vector<int>& p : points) {
					if (pq.size() < K) { pq.push(p); }
					else {
						vector<int> top = pq.top();
						if (top[0] * top[0] + top[1] * top[1] > p[0] * p[0] + p[1] * p[1]) { pq.pop(); pq.push(p); }
					}
				}
				while (!pq.empty()) {
					result.push_back(pq.top());
					pq.pop();
				}
				return result;
			}

		}

		void Main() {
			vector<vector<int>> test = { {1,3},{-2,2} };
			print(PriorityQueue::kClosest(test, 1));
		}
	}
}

