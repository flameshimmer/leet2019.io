#include "stdafx.h"

//Given an undirected graph, return true if and only if it is bipartite.
//Recall that a graph is bipartite if we can split it's set of nodes into two
//independent subsets A and B such that every edge in the graph has one node in A
//and another node in B.
//The graph is given in the following form: graph[i] is a list of indexes j for
//which the edge between nodes i and j exists.  Each node is an integer between 0
//and graph.length - 1.  There are no self edges or parallel edges: graph[i] does
//not contain i, and it doesn't contain any element twice.
//
//Example 1:
//Input: [[1,3], [0,2], [1,3], [0,2]]
//Output: true
//Explanation: 
//The graph looks like this:
//0----1
//|    |
//|    |
//3----2
//We can divide the vertices into two groups: {0, 2} and {1, 3}.
//
//Example 2:
//Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
//Output: false
//Explanation: 
//The graph looks like this:
//0----1
//| \  |
//|  \ |
//3----2
//We cannot find a way to divide the set of nodes into two independent subsets.
// 
//
//Note:
//graph will have length in range [1, 100].
//graph[i] will contain integers in range [0, graph.length - 1].
//graph[i] will not contain i or duplicate values.
//The graph is undirected: if any element j is in graph[i], then i will be in
//graph[j]. 

namespace Solution2019
{
	namespace IsGraphBipartite
	{
		namespace DFS {
			bool dfs(vector<vector<int>>& graph, int i, vector<int>& color, int curColor) {
				if (color[i]) { return color[i] == curColor; }

				color[i] = curColor;
				for (int n : graph[i]) {
					if (!dfs(graph, n, color, -curColor)) { return false; }
				}
				return true;
			}



			bool isBipartite(vector<vector<int>>& graph) {
				int len = graph.size();
				if (len < 2) { return true; }
				vector<int> color(len, 0);
				for (int i = 0; i < len; i++) {
					if (!color[i] && !dfs(graph, i, color, 1)) {
						return false;
					}
				}
				return true;
			}
		}

		namespace BFS {
			bool isBipartite(vector<vector<int>>& graph) {
				int len = graph.size();
				if (len < 2) { return true; }

				vector<int> color(len, 0);

				for (int i = 0; i < len; i++) {
					if (color[i]) { continue; }
					color[i] = 1;
					queue<int> q;
					q.push(i);
					while (!q.empty()) {
						int cur = q.front();
						q.pop();
						for (int n : graph[cur]) {
							if (color[n] == color[cur]) { return false; }
							if (!color[n]) {
								q.push(n);
								color[n] = -color[cur];
							}
						}
					}
				}
				return true;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

