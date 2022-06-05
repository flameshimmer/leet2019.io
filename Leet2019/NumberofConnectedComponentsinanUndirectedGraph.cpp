#include "stdafx.h"

//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge
//is a pair of nodes), write a function to find the number of connected
//components in an undirected graph.
//
//Example 1:
//Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]
//     0          3
//     |          |
//     1 --- 2    4 
//Output: 2
//
//Example 2:
//Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]
//     0           4
//     |           |
//     1 --- 2 --- 3
//Output:  1
//
//Note:
//You can assume that no duplicate edges will appear in edges. Since all edges
//are undirected, [0, 1] is the same as [1, 0] and thus will not appear together
//in edges. 

namespace Solution2019
{
	namespace NumberofConnectedComponentsinanUndirectedGraph
	{
		namespace UnionFind {
			int find(vector<int>& parent, int v) {
				if (parent[v] == v) { return v; }
				return find(parent, parent[v]);
			}

			int countComponents(int n, vector<vector<int>>& edges) {
				if (n == 0) { return 0; }
				int len = edges.size();
				if (len == 0) { return n; }

				vector<int> parent(n);
				for (int i = 0; i < n; i++) { parent[i] = i; }

				for (vector<int>& e : edges) {
					int p0 = find(parent, e[0]);
					int p1 = find(parent, e[1]);
					if (p0 != p1) { parent[p1] = p0; n--; }
				}
				return n;
			}
		}

		namespace DFS {
			void dfs(int i, unordered_set<int>& visited, unordered_map<int, set<int>>& adj) {
				if (visited.find(i) != visited.end()) { return; }
				visited.insert(i);
				for (int child : adj[i]) { dfs(child, visited, adj); }
			}


			int countComponents(int n, vector<vector<int>>& edges) {
				unordered_map<int, set<int>> adj;
				unordered_set<int> visited;

				for (vector<int>& e : edges) {
					adj[e[0]].insert(e[1]);
					adj[e[1]].insert(e[0]);
				}
				int result = 0;
				for (int i = 0; i < n; i++) {
					if (visited.find(i) == visited.end()) {
						result++;
						dfs(i, visited, adj);
					}
				}
				return result;
			}
		}

		void Main() {
			vector<vector<int>> test = { {0, 1}, {1, 2}, {3, 4} };
			print(UnionFind::countComponents(5, test));
		}
	}
}

