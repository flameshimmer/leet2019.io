#include "stdafx.h"
//There are n servers numbered from 0 to n-1 connected by undirected 
//server-to-server connections forming a network where 
//connections[i] = [a, b] represents a connection between servers a and b.
//Any server can reach any other server directly or indirectly through the network.
//
//A critical connection is a connection that, if removed, will make 
//some server unable to reach some other server.
//
//Return all critical connections in the network in any order.
//
//Example 1:
//Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
//Output: [[1,3]]
//Explanation: [[3,1]] is also accepted.
// 
//Constraints:
//1 <= n <= 10^5
//n-1 <= connections.length <= 10^5
//connections[i][0] != connections[i][1]
//There are no repeated connections.

namespace Solution2019
{
	namespace CriticalConnectionsinaNetwork
	{
		int time;
		vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
			vector<vector<int>> neighbors(n, vector<int>());
			for (auto& con : connections) {
				neighbors[con[0]].push_back(con[1]);
				neighbors[con[1]].push_back(con[0]);
			}

			time = 0;
			vector<int> low(n, -1);
			vector<vector<int>> result;
			dfs(neighbors, 0, -1, low, result);
			return result;
		}

		void dfs(vector<vector<int>>& neighbors, int i, int parent, vector<int>& low, vector<vector<int>>& result) {
			time++;
			int curt = time;
			low[i] = curt;

			for (int j : neighbors[i]) {
				if (j == parent) { continue; }
				if (low[j] < 0) {
					dfs(neighbors, j, i, low, result);
				}
				if (low[j] > curt) {
					result.push_back({ i, j });
				}
				low[i] = min(low[i], low[j]);
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

