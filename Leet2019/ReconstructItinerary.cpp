#include "stdafx.h"
//Given a list of airline tickets represented by pairs of departure and arrival 
//airports [from, to], reconstruct the itinerary in order. All of the tickets 
//belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
//
//Note:
//If there are multiple valid itineraries, you should return the itinerary that
//has the smallest lexical order when read as a single string. For example,
//the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//All airports are represented by three capital letters (IATA code).
//You may assume all tickets form at least one valid itinerary.
//
//Example 1:
//Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
//
//Example 2:
//Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
//Explanation: 
//Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
//But it is larger in lexical order.

namespace Solution2019
{
	namespace ReconstructItinerary
	{
		void dfs(string city, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& result) {
			auto& edges = graph[city];
			while (!edges.empty()) {
				string dest = edges.top();
				edges.pop();
				dfs(dest, graph, result);
			}
			result.push_back(city);
		}


		vector<string> findItinerary(vector<vector<string>>& tickets) {
			unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
			for (vector<string>& t : tickets) {
				graph[t[0]].push(t[1]);
			}
			vector<string> result;
			dfs("JFK", graph, result);
			reverse(result.begin(), result.end());
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

