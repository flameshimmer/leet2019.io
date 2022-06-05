#include "stdafx.h"

namespace Solution2019
{
	namespace Test {

		struct Node {
			string city;
			int cost;
			int leg;
			vector<string> path;
			Node(string cityV, int costV, int l, vector<string>& p) : city(cityV), cost(costV), leg(l), path(p){}

			bool operator< (const Node& rhs) const {
				return cost > rhs.cost;
			}
		};
		
		
		int GetCheapestPath(vector<vector<string>> A, int k, string start, string end) {
			int len = A.size();
			if (len == 0 || k == 0) { return 0; }

			unordered_map<string, vector<pair<string, int>>> adj;
			for (vector<string>& a : A) {
				adj[a[0]].push_back({ a[1], stoi(a[2]) });
			}

			priority_queue<Node> pq;
			pq.push({ start, 0, k, vector<string>()});
			string city;
			int cost;
			int leg;
			while (!pq.empty()) {
				Node n = pq.top();
				pq.pop();
				city = n.city;
				cost = n.cost;
				leg = n.leg;
				vector<string>& p = n.path;

				if (city == end) { 
					for (string s : p) {
						cout << s << "->";
					}
					cout << end << endl;
					return cost; 
				}
				if (leg == 0) { continue; }
				p.push_back(city);
				for (auto& n : adj[city]) {
					pq.push({ n.first, cost + n.second, leg - 1, p });
				}
			}
			return -1;
		}

		void Main() {
			vector<vector<string>> A = { {"A", "B", "100"}, {"A", "C", "120"}, {"C", "B", "80"} };
			print(GetCheapestPath(A, 2, "A", "B"));
			print(GetCheapestPath(A, 1, "A", "B"));
			print(GetCheapestPath(A, 0, "A", "B"));

			A = { {"A", "B", "100"}, {"A", "C", "120"}, {"C", "B", "80"}, {"C", "D", "20"} };
			print(GetCheapestPath(A, 2, "B", "D"));

			A = { {"A", "B", "100"}, {"A", "C", "120"}, {"C", "B", "80"}, {"C", "D", "20"} };
			print(GetCheapestPath(A, 1, "A", "D"));
			print(GetCheapestPath(A, 2, "A", "D"));

			A = { {"A", "B", "10"}, {"B", "C", "20"}, {"C", "A", "30"} };
			print(GetCheapestPath(A, 2, "A", "A"));

			print(string("Hello World"));
		}
	}

}
