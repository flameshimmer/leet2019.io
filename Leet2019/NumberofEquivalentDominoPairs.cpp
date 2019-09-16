#include "stdafx.h"
//Given a list of dominoes, dominoes[i] = [a, b] is equivalent to 
//dominoes[j] = [c, d] if and only if either (a==c and b==d), 
//or (a==d and b==c) - that is, one domino can be rotated to 
//be equal to another domino.
//
//Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, 
//and dominoes[i] is equivalent to dominoes[j].
//
//Example 1:
//Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
//Output: 1
//
//Constraints:
//1 <= dominoes.length <= 40000
//1 <= dominoes[i][j] <= 9

namespace Solution2019
{
	namespace NumberofEquivalentDominoPairs
	{
		int numEquivDominoPairs(vector<vector<int>>& dominoes) {
			int result = 0;
			int len = dominoes.size();
			if (len < 2) {
				return result;
			}
			unordered_map<int, int> map;
			for (vector<int> d : dominoes) {
				int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);			
				map[key] ++;
			}
			for (auto& it : map) {
				result += it.second * it.second - 1 / 2;
			}
			return result;
		}
		void Main() {
			vector<vector<int>> input = { {1,2},{2,1},{3,4},{5,6} };
			print(numEquivDominoPairs(input));
		}
	}
}

