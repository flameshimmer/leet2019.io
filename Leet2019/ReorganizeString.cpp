#include "stdafx.h"

//Given a string S, check if the letters can be rearranged so that two characters
//that are adjacent to each other are not the same.
//If possible, output any possible result.  If not possible, return the empty
//string.
//
//Example 1:
//Input: S = "aab"
//Output: "aba"
//
//Example 2:
//Input: S = "aaab"
//Output: ""
//
//Note:
//S will consist of lowercase letters and have length in range [1, 500].

namespace Solution2019
{
	namespace ReorganizeString
	{
		string reorganizeString(string S) {
			int len = S.size();
			if (len < 2) { return S; }
			unordered_map<char, int> map;
			for (char c : S) { map[c]++; }

			char maxChar;
			int maxCount = 0;
			for (auto& p : map) {
				if (p.second > maxCount) {
					maxCount = p.second;
					maxChar = p.first;
				}
			}

			if (maxCount > (len + 1) / 2) { return ""; }

			string result(len, 0);
			int i = 0;
			for (; i < len && map[maxChar] > 0; i += 2) {
				result[i] = maxChar;
				map[maxChar]--;
			}
			for (auto& p : map) {
				while (p.second > 0) {
					if (i >= len) { i = 1; }
					result[i] = p.first;
					p.second--;
					i += 2;
				}
			}
			return result;
		}

		string reorganizeStringWithSort(string S) {
			int map[26] = { 0 };
			int len = S.size();
			for (char c : S) { map[c - 'a']++; }
			vector<pair<int, char>> charCounts;
			for (int i = 0; i < 26; i++) {
				if (map[i] > (len + 1) / 2) { return ""; }
				if (map[i] > 0) { charCounts.push_back({ map[i], i + 'a' }); }
			}

			sort(charCounts.rbegin(), charCounts.rend());
			string sorted;
			for (auto& p : charCounts) {
				sorted += string(p.first, p.second);
			}

			string result;
			for (int i = 0, j = (len + 1) / 2; i < (len + 1) / 2; i++, j++) {
				result += sorted[i];
				if (j < len) { result += sorted[j]; }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(reorganizeString("aaab"));
		}
	}
}

