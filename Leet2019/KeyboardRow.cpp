#include "stdafx.h"
//Given a List of words, return the words that can be typed using 
//letters of alphabet on only one row's of American keyboard like 
//the image below.
// 
//Example:
//
//Input: ["Hello", "Alaska", "Dad", "Peace"]
//Output: ["Alaska", "Dad"]

namespace Solution2019
{
	namespace KeyboardRow
	{
		vector<string> findWordsWithSet(vector<string>& words) {
			unordered_set<char> dict1 = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' };
			unordered_set<char> dict2 = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L' };
			unordered_set<char> dict3 = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M' };

			vector<string> result;
			for (string w : words) {
				bool d1 = true;
				bool d2 = true;
				bool d3 = true;
				for (char c : w) {
					if (d1) {
						if (dict1.find(c) == dict1.end()) { d1 = false; }
					}
					if (d2) {
						if (dict2.find(c) == dict2.end()) { d2 = false; }
					}
					if (d3) {
						if (dict3.find(c) == dict3.end()) { d3 = false; }
					}
				}
				if (d1 || d2 || d3) { result.push_back(w); }
			}
			return result;
		}

		vector<string> findWords(vector<string>& words) {
			vector<string> rows = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
			vector<string> result;

			for (string s : words) {
				bool found = true;
				string candidate = "";
				for (char c : s) {
					c = tolower(c);
					if (candidate.empty()) {
						for (string r : rows) {
							if (r.find(c) != string::npos) { candidate = r; break; }
						}
					}
					if (candidate.find(c) == string::npos) { found = false; break; }
				}
				if (found) { result.push_back(s); }
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

