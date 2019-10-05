#include "stdafx.h"
// 

namespace Solution2019
{
	namespace ReverseOnlyLetters
	{
		string reverseOnlyLetters(string S) {
			string result = S;
			int start = 0;
			int end = result.size() - 1;
			while (start < end) {
				while (start < end && !isalpha(result[start])) { start++; }
				while (start < end && !isalpha(result[end])) { end--; }
				if (start == end) { return result; }

				char tmp = result[start];
				result[start] = result[end];
				result[end] = tmp;
				start++;
				end--;
			}
			return result;
		}
		void Main() {
			print(reverseOnlyLetters("ab-cd"));
		}
	}
}

