
#include "stdafx.h"
//Given a string text, you want to use the characters of text to 
//form as many instances of the word "balloon" as possible.
//
//You can use each character in text at most once.Return the 
//maximum number of instances that can be formed.
//
//Example 1:
//Input: text = "nlaebolko"
//Output : 1
//
//Example 2 :
//Input : text = "loonbalxballpoon"
//Output : 2
//
//Example 3 :
//Input : text = "leetcode"
//Output : 0
//
//Constraints :
//1 <= text.length <= 10 ^ 4
//text consists of lower case English letters only.
//
namespace Solution2019
{
	namespace MaximumNumberofBalloons
	{

		int maxNumberOfBalloons(string text) {
			int map[26] = { 0 };
			for (char c : text) {
				map[c - 'a']++;
			}

			string tmp = "balloon";
			int target[26] = { 0 };
			for (char c : tmp) {
				target[c - 'a']++;
			}

			int result = INT_MAX;
			for (int i = 0; i < 26; i++) {
				if (target[i] > 0) {
					result = min(result, map[i] / target[i]);
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

