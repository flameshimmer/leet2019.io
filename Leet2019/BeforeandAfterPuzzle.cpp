#include "stdafx.h"
//Given a list of phrases, generate a list of Before and After puzzles.
//
//A phrase is a string that consists of lowercase English letters and 
//spaces only. No space appears in the start or the end of a phrase. 
//There are no consecutive spaces in a phrase.
//
//Before and After puzzles are phrases that are formed by merging two 
//phrases where the last word of the first phrase is the same as the 
//first word of the second phrase.
//
//Return the Before and After puzzles that can be formed by every two 
//phrases phrases[i] and phrases[j] where i != j. Note that the order 
//of matching two phrases matters, we want to consider both orders.
//
//You should return a list of distinct strings sorted lexicographically.
//
//Example 1:
//Input: phrases = ["writing code","code rocks"]
//Output: ["writing code rocks"]
//
//Example 2:
//Input: phrases = ["mission statement",
//                  "a quick bite to eat",
//                  "a chip off the old block",
//                  "chocolate bar",
//                  "mission impossible",
//                  "a man on a mission",
//                  "block party",
//                  "eat my words",
//                  "bar of soap"]
//Output: ["a chip off the old block party",
//         "a man on a mission impossible",
//         "a man on a mission statement",
//         "a quick bite to eat my words",
//         "chocolate bar of soap"]
//
//Example 3:
//Input: phrases = ["a","b","a"]
//Output: ["a"]
// 
//Constraints:
//1 <= phrases.length <= 100
//1 <= phrases[i].length <= 100

namespace Solution2019
{
	namespace BeforeandAfterPuzzle
	{
		void getFirstLast(string& s, string& f, string& l) {
			int start = 0;
			int end = 0;
			int len = s.size();
			while (end < len && s[end] != ' ') { end++; }
			f = s.substr(0, end - start);

			end = len - 1;
			start = len - 1;
			while (start >= 0 && s[start] != ' ') { start--; }
			l = s.substr(start + 1, end - start + 1);
		}

		vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
			unordered_map<string, vector<int>> first;
			unordered_map<string, vector<int>> last;

			string fp = "";
			string lp = "";
			for (int i = 0; i < phrases.size(); i++) {
				if (empty(phrases[i])) { continue; }
				getFirstLast(phrases[i], fp, lp);
				first[fp].push_back(i);
				last[lp].push_back(i);
			}

			set<string> result;
			for (auto& l : last) {
				if (first.find(l.first) != first.end()) {
					for (int i : l.second) {
						for (int j : first[l.first]) {
							if (i == j) { continue; }
							result.insert(phrases[i] + phrases[j].substr(l.first.size())); //--> substr returns "" when pos is equal to len, but will break if pos is larger than len
						}
					}
				}
			}
			vector<string> results(result.begin(), result.end());
			return results;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

