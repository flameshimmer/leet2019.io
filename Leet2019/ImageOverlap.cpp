#include "stdafx.h"
//Two images A and B are given, represented as binary, square matrices 
//of the same size.  (A binary matrix has only 0s and 1s as values.)
//
//We translate one image however we choose (sliding it left, right, up, 
//or down any number of units), and place it on top of the other image.  
//After, the overlap of this translation is the number of positions that 
//have a 1 in both images.
//
//(Note also that a translation does not include any kind of rotation.)
//
//What is the largest possible overlap?
//
//Example 1:
//Input: A = [[1,1,0],
//            [0,1,0],
//            [0,1,0]]
//       B = [[0,0,0],
//            [0,1,1],
//            [0,0,1]]
//Output: 3
//Explanation: We slide A to right by 1 unit and down by 1 unit.
//
//Notes: 
//1 <= A.length = A[0].length = B.length = B[0].length <= 30
//0 <= A[i][j], B[i][j] <= 1

namespace Solution2019
{
	namespace ImageOverlap
	{
		int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
			vector<pair<int, int>> A1;
			vector<pair<int, int>> B1;
			for (int i = 0; i < A.size(); i++) {
				for (int j = 0; j < A[0].size(); j++) {
					if (A[i][j] == 1) { A1.push_back(make_pair(i, j)); }
				}
			}

			for (int i = 0; i < B.size(); i++) {
				for (int j = 0; j < B[0].size(); j++) {
					if (B[i][j] == 1) { B1.push_back(make_pair(i, j)); }
				}
			}

			unordered_map<string, int> map;
			for (pair<int, int> a : A1) {
				for (pair<int, int> b : B1) {
					map[to_string(a.first - b.first) + "," + to_string(a.second - b.second)] ++;
				}
			}
			int result = 0;
			for (auto& p : map) {
				result = max(result, p.second);
			}
			return result;
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

