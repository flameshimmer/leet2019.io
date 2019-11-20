#include "stdafx.h"

//Given a paragraph and a list of banned words, return the most frequent word
//that is not in the list of banned words.  It is guaranteed there is at least
//one word that isn't banned, and that the answer is unique.
//Words in the list of banned words are given in lowercase, and free of
//punctuation.  Words in the paragraph are not case sensitive.  The answer is in
//lowercase.
// 
//
//Example:
//Input: 
//paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
//banned = ["hit"]
//Output: "ball"
//Explanation: 
//"hit" occurs 3 times, but it is a banned word.
//"ball" occurs twice (and no other word does), so it is the most frequent
//non-banned word in the paragraph. 
//
//Note that words in the paragraph are not case sensitive,
//that punctuation is ignored (even if adjacent to words, such as "ball,"), 
//and that "hit" isn't the answer even though it occurs more because it is
//banned.
// 
//
//Note:
//1 <= paragraph.length <= 1000.
//0 <= banned.length <= 100.
//1 <= banned[i].length <= 10.
//The answer is unique, and written in lowercase (even if its occurrences in
//paragraph may have uppercase symbols, and even if it is a proper noun.)
//paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
//There are no hyphens or hyphenated words.
//Words only consist of letters, never apostrophes or other punctuation symbols.

namespace Solution2019
{
	namespace MostCommonWord
	{

		string mostCommonWord(string paragraph, vector<string>& banned) {
			unordered_set<string> banset(banned.begin(), banned.end());
			for (char& c : paragraph) { //--> modifying the input! so we can use istringstream later
				c = isalnum(c) ? tolower(c) : ' ';
			}

			istringstream ss(paragraph);
			string cur;
			unordered_map<string, int> wc;
			pair<string, int> result = { "", 0 }; // keep track of max as we add things into the hashmap!
			while (ss >> cur) {
				if (banset.find(cur) != banset.end()) { continue; }
				wc[cur]++;
				if (wc[cur] > result.second) { result = { cur, wc[cur] }; }
			}
			return result.first;
		}


		namespace Another {
			vector<string> splitWords(string p) {
				vector<string> words;
				int len = p.size();
				int start = 0;
				int end = 0;
				while (end < len) {
					while (end < len && !isalnum(p[end])) { end++; }
					if (end == len) { break; }
					start = end;
					while (end < len && isalnum(p[end])) { end++; }
					words.push_back(p.substr(start, end - start));
				}
				return words;
			}


			string mostCommonWord(string paragraph, vector<string>& banned) {
				unordered_set<string> ban(banned.begin(), banned.end());
				unordered_map<string, int> wc;
				vector<string> words = splitWords(paragraph);
				for (string w : words) {
					transform(w.begin(), w.end(), w.begin(), ::tolower);
					if (ban.find(w) == ban.end()) { wc[w]++; }
				}
				vector<pair<int, string>> list;
				for (auto& p : wc) {
					list.push_back({ p.second, p.first });
				}
				sort(list.begin(), list.end());
				return list.back().second;
			}
		}


		void Main() {
			//vector<string> banned = { "a" };
			//print(mostCommonWord("a, a, a, a, b,b,b,c, c", banned));
			vector<string> banned = { "hit" };
			print(mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", banned));
		}
	}
}

