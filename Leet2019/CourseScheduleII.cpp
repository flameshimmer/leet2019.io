#include "stdafx.h"

//There are a total of n courses you have to take, labeled from 0 to n-1.
//Some courses may have prerequisites, for example to take course 0 you have to
//first take course 1, which is expressed as a pair: [0,1]
//Given the total number of courses and a list of prerequisite pairs, return the
//ordering of courses you should take to finish all courses.
//There may be multiple correct orders, you just need to return one of them. If
//it is impossible to finish all courses, return an empty array.
//
//Example 1:
//Input: 2, [[1,0]] 
//Output: [0,1]
//Explanation: There are a total of 2 courses to take. To take course 1 you
//should have finished   
//             course 0. So the correct course order is [0,1] .
//
//Example 2:
//Input: 4, [[1,0],[2,0],[3,1],[3,2]]
//Output: [0,1,2,3] or [0,2,1,3]
//Explanation: There are a total of 4 courses to take. To take course 3 you
//should have finished both     
//             courses 1 and 2. Both courses 1 and 2 should be taken after you
//finished course 0. 
//             So one correct course order is [0,1,2,3]. Another correct ordering
//is [0,2,1,3] .
//
//Note:
//The input prerequisites is a graph represented by a list of edges, not
//adjacency matrices. Read more about how a graph is represented.
//You may assume that there are no duplicate edges in the input prerequisites. 

namespace Solution2019
{
	namespace CourseScheduleII
	{
		vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
			vector<vector<int>> adj(n, vector<int>());
			vector<int> indegree(n, 0);
			for (vector<int>& p : prerequisites) {
				adj[p[1]].push_back(p[0]);
				indegree[p[0]]++;
			}

			queue<int> q;
			for (int i = 0; i < n; i++) {
				if (indegree[i] == 0) { q.push(i); }
			}

			int total = 0;
			vector<int> result;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				total++;
				result.push_back(cur);
				for (int n : adj[cur]) {
					indegree[n]--;
					if (indegree[n] == 0) { q.push(n); }
				}
			}
			return (total == n) ? result : vector<int>();
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

