#include "stdafx.h"
#include <array>
//Given an array A of strings made only from lowercase letters, 
//return a list of all characters that show up in all strings 
//within the list(including duplicates).For example, if a character 
//occurs 3 times in all strings but not 4 times, you need to include
//that character three times in the final answer.
//
//You may return the answer in any order.
//
//Example 1:
//Input: ["bella", "label", "roller"]
//Output : ["e", "l", "l"]
//
//Example 2 :
//Input : ["cool", "lock", "cook"]
//Output : ["c", "o"]
//
//Note :
//1 <= A.length <= 100
//1 <= A[i].length <= 100
//A[i][j] is a lowercase letter

namespace Solution2019
{
	namespace FindCommonCharacters
	{
		vector<string> FindCommonCharactersSlow(vector<string>& A) {
			vector<vector<int>> maps(A.size(), vector<int>(26, 0));

			for (int i = 0; i < A.size(); i++) {
				for (char c : A[i]) { maps[i][c - 'a']++; }
			}

			vector<string> result;
			for (int i = 0; i < 26; i++) {
				int minVal = INT_MAX;
				for (auto& map : maps) {
					minVal = min(minVal, map[i]);
				}
				while (minVal > 0) { result.push_back(string(1, 'a' + i)); minVal--; }
			}
			return result;
		}

		vector<string> FindCommonCharactor(vector<string>& A) {
			int global[26];
			for (int i = 0; i < 26; i++) { global[i] = INT_MAX; }

			for (string str : A) {
				int local[26] = { 0 };
				for (char c : str) {
					local[c - 'a']++;
				}
				for (int i = 0; i < 26; i++) {
					global[i] = min(global[i], local[i]);
				}
			}
			vector<string> result;
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < global[i]; j++) { result.push_back(string(1, 'a' + i)); }
			}
			return result;
		}

		void Main() {
			vector<string> A = { "bella", "label", "roller" };
			print(FindCommonCharactor(A));
			//print(FindCommonCharacters({ "cool", "lock", "cook" }));
		}
	}
}

