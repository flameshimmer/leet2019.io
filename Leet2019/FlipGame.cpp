#include "stdafx.h"
//You are playing the following Flip Game with your friend: 
//Given a string that contains only these two characters: + and -, 
//you and your friend take turns to flip two consecutive "++" into "--". 
//The game ends when a person can no longer make a move and 
//therefore the other person will be the winner.
//
//Write a function to compute all possible states of the string after one valid move.
//
//Example:
//
//Input: s = "++++"
//Output: 
//[
//  "--++",
//  "+--+",
//  "++--"
//]
//Note: If there is no valid move, return an empty list [].

namespace Solution2019
{
	namespace FlipGame
	{
		vector<string> generatePossibleNextMoves(string s) {
			vector<string> result;
			int len = s.size();
			if (len < 2) { return result; }

			for (int i = 1; i < s.size(); i++) {
				if (s[i] == '+' && s[i - 1] == '+') {
					string r = s;
					r[i] = '-';
					r[i - 1] = '-';
					result.push_back(r);
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

