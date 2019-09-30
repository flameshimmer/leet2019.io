#include "stdafx.h"
//Given words first and second, consider occurrences in some text
//of the form "first second third", where second comes immediately
//after first, and third comes immediately after second.
//
//For each such occurrence, add "third" to the answer,
//and return the answer.
//
//Example 1:
//Input: text = "alice is a good girl she is a good student", 
//first = "a", second = "good"
//Output: ["girl","student"]
//
//Example 2:
//Input: text = "we will we will rock you", 
//first = "we", second = "will"
//Output: ["we","rock"]
// 
//
//Note:
//1 <= text.length <= 1000
//text consists of space separated words, where 
//each word consists of lowercase English letters.
//1 <= first.length, second.length <= 10
//first and second consist of lowercase English letters.

namespace Solution2019
{
	namespace OccurrencesAfterBigram
	{
		vector<string> findOcurrences(string text, string first, string second) {
			vector<string> result;
			istringstream ss(text);
			string cur;
			string prev;
			string prev2;
			while (ss >> cur) {
				if (prev2 == first && prev == second) {
					result.push_back(cur);
				}
				prev2 = prev;
				prev = cur;
			}
			return result;
		}

		vector<string> findOcurrencesAnother(string text, string first, string second) {
			vector<string> result;
			string target = " " + first + " " + second + " ";
			text = " " + text;
			size_t stringStart = text.find(target);
			while (stringStart != string::npos) {
				size_t stringEnd = stringStart + target.size();
				size_t cur = stringEnd;
				while (cur < text.size() && text[cur] != ' ') { cur++; }
				result.push_back(text.substr(stringEnd, cur - stringEnd));
				stringStart = text.find(target, stringStart + 1);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

