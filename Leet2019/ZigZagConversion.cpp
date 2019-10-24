#include "stdafx.h"
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given 
//number of rows like this: (you may want to display this pattern in a 
//fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given
//a number of rows:
//
//string convert(string s, int numRows);
//
//Example 1:
//Input: s = "PAYPALISHIRING", numRows = 3
//Output: "PAHNAPLSIIGYIR"
//
//Example 2:
//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
//Explanation:
//
//P     I    N
//A   L S  I G
//Y A   H R
//P     I

namespace Solution2019
{
	namespace ZigZagConversion
	{
		string convert(string s, int numRows) {
			if (numRows <= 1) { return s; }

			int len = s.size();
			vector<string> rows(numRows, "");

			int i = 0;
			int step = 1;
			for (char c : s) {
				rows[i].push_back(c);

				if (i == 0) { step = 1; }
				else if (i == numRows - 1) { step = -1; }
				i += step;
			}

			string result = "";
			for (string s : rows) {
				result += s;
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

