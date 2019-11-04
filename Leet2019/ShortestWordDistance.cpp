#include "stdafx.h"

//Design a class which receives a list of words in the constructor, and
//implements a method that takes two words word1 and word2 and return the
//shortest distance between these two words in the list. Your method will be
//called repeatedly many times with different parameters. 
//
//Example:
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//Input: word1 = “coding”, word2 = “practice”
//Output: 3
//Input: word1 = "makes", word2 = "coding"
//Output: 1
//
//Note:
//You may assume that word1 does not equal to word2, and word1 and word2 are both
//in the list. 

namespace Solution2019
{
	namespace ShortestWordDistance
	{
		int shortestDistance(vector<string>& words, string word1, string word2) {
			int i1 = -1;
			int i2 = -1;
			int result = words.size();
			for (int i = 0; i < words.size(); i++) {
				if (words[i] == word1) { i1 = i; }
				else if (words[i] == word2) { i2 = i; }
				if (i1 >= 0 && i2 >= 0) {
					result = min(result, abs(i1 - i2));
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

