#include "stdafx.h"
//Given a list of words and two words word1 and word2, 
//return the shortest distance between these two words in the list.
//
//word1 and word2 may be the same and they represent two individual 
//words in the list.
//
//Example:
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//Input: word1 = “makes”, word2 = “coding”
//Output: 1
//Input: word1 = "makes", word2 = "makes"
//Output: 3
//
//Note:
//You may assume word1 and word2 are both in the list. 

namespace Solution2019
{
	namespace ShortestWordDistanceIII
	{
		int shortestWordDistance(vector<string> words, string word1, string word2) {
			int i1 = -1;
			int i2 = -1;
			bool same = word1 == word2;
			int result = INT_MAX;
			for (int i = 0; i < words.size(); i++) {
				string w = words[i];
				if (w == word1) {
					if (same) {
						i2 = i1;
						i1 = i;
					}
					else {
						i1 = i;
					}
				}
				else if (w == word2) {
					i2 = i;
				}
				if (i1 >= 0 && i2 >= 0) {
					result = min(result, abs(i2 - i1));
				}
			}
			return result;
		}

		void Main() {
			print(shortestWordDistance({"a", "b"}, "a", "b"));
		}
	}
}

