#include "stdafx.h"
//There is a new alien language which uses the latin alphabet. However, the order 
//among letters are unknown to you. You receive a list of non-empty words from the
//dictionary, where words are sorted lexicographically by the rules of this new 
//language. Derive the order of letters in this language.
//
//Example 1:
//Input:
//[
//  "wrt",
//  "wrf",
//  "er",
//  "ett",
//  "rftt"
//]
//Output: "wertf"
//
//Example 2:
//Input:
//[
//  "z",
//  "x"
//]
//Output: "zx"
//
//Example 3:
//Input:
//[
//  "z",
//  "x",
//  "z"
//] 
//Output: "" 
//Explanation: The order is invalid, so return "".
//
//Note:
//You may assume all letters are in lowercase.
//You may assume that if a is a prefix of b, then a 
//must appear before b in the given dictionary.
//If the order is invalid, return an empty string.
//There may be multiple valid order of letters,
//return any one of them is fine.

namespace Solution2019
{
	namespace AlienDictionary
	{
		namespace BFS {
			string alienOrder(vector<string>& words) {
				int len = words.size();
				unordered_map<char, int> indegree;
				unordered_map<char, unordered_set<char>> adj;

				for (string w : words) {
					for (char c : w) {
						indegree[c] = 0;
					}
				}

				for (int i = 0; i < len - 1; i++) {
					string& w1 = words[i];
					string& w2 = words[i + 1];
					int minLen = min(w1.size(), w2.size());
					for (int j = 0; j < minLen; j++) {
						char c1 = w1[j];
						char c2 = w2[j];
						if (c1 != c2 && adj[c1].count(c2) == 0) {
							adj[c1].insert(c2);
							indegree[c2]++;
							break;
						}
					}
				}

				string result;
				queue<char> q;
				for (auto& p : indegree) {
					if (p.second == 0) { q.push(p.first); }
				}
				while (!q.empty()) {
					char cur = q.front();
					q.pop();
					result.push_back(cur);

					for (char n : adj[cur]) {
						indegree[n]--;
						if (indegree[n] == 0) { q.push(n); }
					}
				}

				return result.size() == indegree.size() ? result : "";
			}
		}
		
		namespace DFS {
			bool dfs(unordered_map<char, unordered_set<char>>& adj, char c, unordered_set<char>& visited, unordered_set<char>& path, string& result) {
				if (path.count(c)) { return false; }
				if (visited.count(c)) { return true; }

				visited.insert(c);
				path.insert(c);
				for (char n : adj[c]) {
					if (!dfs(adj, n, visited, path, result)) { return false; }
				}
				path.erase(c);
				result.push_back(c);
				return true;
			}

			string alienOrder(vector<string>& words) {
				int len = words.size();
				if (len == 0) { return ""; }
				if (len == 1) { return words[0]; }

				unordered_set<char> nodes;
				unordered_map<char, unordered_set<char>> adj;

				for (string w : words) {
					for (char c : w) {
						nodes.insert(c);
					}
				}

				for (int i = 0; i < len - 1; i++) {
					string& w1 = words[i];
					string& w2 = words[i + 1];
					int minLen = min(w1.size(), w2.size());

					for (int j = 0; j < minLen; j++) {
						if (w1[j] != w2[j]) {
							adj[w1[j]].insert(w2[j]);
							break;
						}
					}
				}

				unordered_set<char> visited;
				unordered_set<char> path;
				string result = "";
				for (char c : nodes) {
					if (!dfs(adj, c, visited, path, result)) { return ""; }
				}
				reverse(result.begin(), result.end());
				return result;
			}

		}
		
		void Main() {
			vector<string> test = { "wrt","wrf","er","ett","rftt","te" };
			print(BFS::alienOrder(test));
		}
	}
}

