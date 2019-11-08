#include "stdafx.h"

//There are n cities connected by m flights. Each fight starts from city u and
//arrives at v with a price w.
//Now given all the cities and flights, together with starting city src and the
//destination dst, your task is to find the cheapest price from src to dst with
//up to k stops. If there is no such route, output -1.
//
//Example 1:
//Input: 
//n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
//src = 0, dst = 2, k = 1
//Output: 200
//Explanation: 
//The graph looks like this:
/*
          0 
	     / \
	100	/	\500
	   1-----2
	     100
*/
//The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as
//marked red in the picture.
//
//Example 2:
//Input: 
//n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
//src = 0, dst = 2, k = 0
//Output: 500
//Explanation: 
//The graph looks like this:
/*
		  0
		 / \
	100	/	\500
	   1-----2
		 100
*/
//The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as
//marked blue in the picture.
//
//Note:
//The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n
//- 1.
//The size of flights will be in range [0, n * (n - 1) / 2].
//The format of each flight will be (src, dst, price).
//The price of each flight will be in the range [1, 10000].
//k is in the range of [0, n - 1].
//There will not be any duplicated flights or self cycles.

namespace Solution2019
{
	namespace CheapestFlightsWithinKStops
	{
		namespace Dijkstra {
			typedef tuple<int, int, int> ti;
			int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
				vector<vector<pair<int, int>>> adj(n);
				for (const vector<int>& f : flights) { adj[f[0]].push_back({ f[1], f[2] }); }

				priority_queue<ti, vector<ti>, greater<ti>> pq;
				pq.push({ 0, src, K + 1 });
				while (!pq.empty()) {
					auto [cost, u, stops] = pq.top();
					pq.pop();
					if (u == dst) { return cost; }
					if (stops == 0) { continue; }
					for (const pair<int, int>& p : adj[u]) {
						auto [v, c] = p;
						pq.push({ cost + c, v, stops - 1 });
					}
				}
				return -1;
			}
		}

		namespace BellmanFord {
			int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
				vector<long long> c(n, INT_MAX);
				c[src] = 0;

				for (int i = 0; i <= K; i++) {
					vector<long long> C(c);
					for (auto f : flights) {
						C[f[1]] = min(C[f[1]], c[f[0]] + f[2]);
					}
					c = C;
				}
				return c[dst] == INT_MAX ? -1 : c[dst];
			}
		}

		namespace DFS {
			void dfs(int src, int dest, unordered_map<int, vector<pair<int, int>>>& adj, unordered_set<int>& visited, int K, int sum, int& result)
			{
				if (src == dest) { result = sum; return; }
				if (K == 0) { return; }

				visited.insert(src);
				for (pair<int, int> n : adj[src]) {
					if (visited.find(n.first) == visited.end()) {
						if (sum + n.second > result) { continue; }
						dfs(n.first, dest, adj, visited, K - 1, sum + n.second, result);
					}
				}
				visited.erase(src);
			}


			int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int K) {
				int len = flights.size();
				if (len == 0) { return 0; }

				unordered_set<int> visited;
				unordered_map<int, vector<pair<int, int>>> adj;
				for (vector<int> f : flights) {
					adj[f[0]].push_back({ f[1], f[2] });
				}
				int result = INT_MAX;
				dfs(src, dest, adj, visited, K + 1, 0, result);
				return result == INT_MAX ? -1 : result;
			}
		}
		void Main() {
			vector<vector<int>> test = { {0,1,100},{1,2,100},{0,2,500} };
			print(Dijkstra::findCheapestPrice(3, test, 0, 2, 1));
		}
	}
}

