#include "stdafx.h"
//Given a list of unique words, find all pairs of distinct indices (i, j) 
//in the given list, so that the concatenation of the two words, 
//i.e. words[i] + words[j] is a palindrome.
//
//Example 1:
//
//Input: ["abcd","dcba","lls","s","sssll"]
//Output: [[0,1],[1,0],[3,2],[2,4]] 
//Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
//Example 2:
//
//Input: ["bat","tab","cat"]
//Output: [[0,1],[1,0]] 
//Explanation: The palindromes are ["battab","tabbat"]
//
namespace Solution2019
{
	namespace PalindromePairs
	{
		bool isPalindrome(string& w, int i, int j) {
			while (i < j) {
				if (w[i] != w[j]) { return false; }
				i++;
				j--;
			}
			return true;
		}

		vector<vector<int>> palindromePairs(vector<string>& words) {
			vector<vector<int>> result;
			unordered_map<string, int> dict;
			int len = words.size();
			for (int i = 0; i < len; i++) {
				dict[words[i]] = i;
			}

			for (int i = 0; i < len; i++) {
				string w = words[i];
				for (int j = 0; j <= w.size(); j++) {
					if (isPalindrome(w, j, w.size() - 1)) {
						string prefix = w.substr(0, j);
						reverse(prefix.begin(), prefix.end());
						if (dict.find(prefix) != dict.end() && dict[prefix] != i) {
							result.push_back({ i, dict[prefix] });
						}
					}

					// j>0 avoids the duplicates with 0 length case
					if (j > 0 && isPalindrome(w, 0, j - 1)) {
						string suffix = w.substr(j);
						reverse(suffix.begin(), suffix.end());
						if (dict.find(suffix) != dict.end() && dict[suffix] != i) {
							result.push_back({ dict[suffix], i });
						}
					}
				}
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

