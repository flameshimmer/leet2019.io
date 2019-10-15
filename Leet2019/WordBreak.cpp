#include "stdafx.h"
// 

namespace Solution2019
{
	namespace WordBreak
	{
		namespace Short1 {
			int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
				unordered_set<string> wl(wordList.begin(), wordList.end());
				unordered_set<string> visited;
				int level = 0;

				queue<vector<string>> q;
				q.push({ beginWord });

				while (!q.empty()) {
					vector<string> path = q.front();
					q.pop();

					if (path.size() > level) {
						level = path.size();
						for (string w : visited) {
							wl.erase(w);
						}
						visited.clear();
					}

					string last = path.back();
					for (int i = 0; i < last.size(); i++) {
						string news = last;
						for (char c = 'a'; c < 'z'; c++) {
							if (c == news[i]) { continue; }
							news[i] = c;

							if (wl.find(news) != wl.end()) {
								if (news == endWord) {
									return level + 1;
								}
								else {
									vector<string> newPath = path;
									newPath.push_back(news);
									visited.insert(news);
									q.push(newPath);
								}
							}
						}
					}
				}
				return 0;
			}
		}

		namespace Short2 {
			int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
				unordered_set<string> wl(wordList.begin(), wordList.end());
				queue<string> q;
				q.push(beginWord);
				int level = 1;

				while (!q.empty()) {
					int sz = q.size();
					while (sz) {
						sz--;
						string word = q.front();
						q.pop();
						if (word == endWord) { return level; }
						wl.erase(word);

						for (int i = 0; i < word.size(); i++) {
							char tmp = word[i];
							for (char c = 'a'; c < 'z'; c++) {
								word[i] = c;
								if (wl.find(word) != wl.end()) {
									q.push(word);
								}
								word[i] = tmp;
							}
						}
					}
					level++;
				}
				return 0;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

