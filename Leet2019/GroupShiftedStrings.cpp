#include "stdafx.h"

//Given a string, we can "shift" each of its letter to its successive letter, for
//example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//"abc" -> "bcd" -> ... -> "xyz"
//Given a list of strings which contains only lowercase alphabets, group all
//strings that belong to the same shifting sequence.
//
//Example:
//Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
//Output: 
//[
//  ["abc","bcd","xyz"],
//  ["az","ba"],
//  ["acef"],
//  ["a","z"]
//]

namespace Solution2019
{
	namespace GroupShiftedStrings
	{
		string getKey(string& s) {
			if (s.empty()) { return ""; }
			vector<int> key;
			for (char c : s) {
				key.push_back(c - 'a');
			}
			int diff = key[0] - 0;
			for (int i = 0; i < key.size(); i++) {
				key[i] = (key[i] - diff + 26) % 26;
			}
			string result;
			for (int v : key) {
				result += to_string(v) + "_";
			}
			return result;
		}


		vector<vector<string>> groupStrings(vector<string>& strings) {
			vector<vector<string>> results;
			int len = strings.size();
			if (len == 0) { return results; }
			unordered_map<string, vector<string>> map;
			for (string s : strings) {
				map[getKey(s)].push_back(s);
			}
			for (auto& p : map) { results.push_back(p.second); }
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

