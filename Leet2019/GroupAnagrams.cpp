#include "stdafx.h"
//Given an array of strings, group anagrams together.
//
//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Output:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//Note:
//
//All inputs will be in lowercase.
//The order of your output does not matter.

namespace Solution2019
{
	namespace GroupAnagrams
	{
		string getKey(string& s) {
			int map[26] = { 0 };
			for (char c : s) {
				map[c - 'a']++;
			}

			string result = "";
			for (int i = 0; i < 26; i++) {
				if (map[i] > 0) {
					char c = 'a' + i;
					result += c + to_string(map[i]);
				}
			}
			return result;
		}

		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			vector<vector<string>> result;
			unordered_map<string, vector<string>> map;
			for (string s : strs) {
				map[getKey(s)].push_back(s);
			}

			for (auto& p : map) {
				result.push_back(p.second);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

