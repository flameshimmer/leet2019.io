#include "stdafx.h"
//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//
//Input: ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
//Note:
//
//All given inputs are in lowercase letters a-z. 

namespace Solution2019
{
	namespace LongestCommonPrefix
	{
		string LongestCommonPrefix(vector<string> input) {
			string result = "";
			if (input.empty()) { return result; }
			int minLen = INT_MAX;
			for (string s : input) {
				minLen = min(minLen, (int)s.size());
			}
			for (int i = 0; i < minLen; i++)
			{
				for (int j = 0; j<input.size() - 1; j++) // one less loop
				{
					if (input[j][i] != input[j + 1][i]) { return result; }
				}
				result += input[0][i]; // don't need  input[j][i] here, just use  input[0][i]
			}
			return result;
		}

		string LongestCommonPrefixSlow(vector<string> input) {
			string result = "";
			if (input.empty()) { return result; }
			int minLen = INT_MAX;
			for (string s : input) {
				minLen = min(minLen, (int)s.size());
			}
			for (int i = 0; i < minLen; i++)
			{
				char cur = input[0][i];
				for (string s : input) {
					if (s[i] != cur) { return result; }
				}
				result += cur;
			}
			return result;
		}


		void Main() {
			string test = "tst test test";
			print(LongestCommonPrefix({ "flower", "flow", "flight" }));
			print(LongestCommonPrefix({ "dog", "racecar", "car" }));
		}
	}
}

