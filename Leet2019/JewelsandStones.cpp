#include "stdafx.h"
//You're given strings J representing the types of stones that are 
//jewels, and S representing the stones you have.  Each character 
//in S is a type of stone you have.  You want to know how many of 
//the stones you have are also jewels.
//
//The letters in J are guaranteed distinct, and all characters in 
//Jand S are letters.Letters are case sensitive, so "a" is 
//considered a different type of stone from "A".
//
//Example 1:
//
//Input: J = "aA", S = "aAAbbbb"
//Output : 3
//
//Example 2 :
//Input : J = "z", S = "ZZ"
//Output : 0
//Note :
//S and J will consist of letters and have length at most 50.
//The characters in J are distinct.

namespace Solution2019
{
	namespace JewelsandStones
	{
		int numJewelsInStones(string J, string S) {
			bool map[256] = { false };
			for (char c : J) { map[c] = true; }
			
			int result = 0;
			for (char c : S) {
				if (map[c]) { result++; }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

