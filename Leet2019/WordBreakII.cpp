#include "stdafx.h"
// 

namespace Solution2019
{
	namespace WordBreakII
	{
		vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wl) {
			vector<vector<string>> ans;
			queue<vector<string>> paths;
			unordered_set<string> wordList(wl.begin(), wl.end());
			paths.push({ beginWord });
			int level = 1;
			int minLevel = INT_MAX;

			unordered_set<string> visited;

			while (!paths.empty()) {
				vector<string> path = paths.front();
				paths.pop();

				if (path.size() > level) {
					for (string w : visited) { wordList.erase(w); }
					visited.clear();
					if (path.size() > minLevel) { break; }
					else { level = path.size(); }
				}

				string last = path.back();
				for (int i = 0; i < last.size(); i++) {
					string news = last;
					for (char c = 'a'; c <= 'z'; c++) {
						news[i] = c;
						if (wordList.find(news) != wordList.end()) {
							vector<string> newpath = path;
							newpath.push_back(news);
							visited.insert(news);

							if (news == endWord) {
								minLevel = level;
								ans.push_back(newpath);
							}
							else {
								paths.push(newpath);
							}
						}
					}
				}
			}
			return ans;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

