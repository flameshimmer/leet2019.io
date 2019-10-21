#include "stdafx.h"
//Given two words (beginWord and endWord), and a dictionary's word list, 
//find all shortest transformation sequence(s) from beginWord to endWord, such that:
//Only one letter can be changed at a time
//Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//Note:
//Return an empty list if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.
//You may assume beginWord and endWord are non-empty and are not the same.
//
//Example 1:
//Input:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//Output:
//[
//  ["hit","hot","dot","dog","cog"],
//  ["hit","hot","lot","log","cog"]
//]
//
//Example 2:
//Input:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//Output: []
//
//Explanation: The endWord "cog" is not in wordList, 
//therefore no possible transformation.

namespace Solution2019
{
	namespace WordLadderII
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

