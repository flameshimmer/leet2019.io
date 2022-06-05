#include "stdafx.h"

//Given Aand B two interval lists, A has no overlap inside Aand B has no overlap
//inside B.Write the function to merge two interval lists, output the result with
//no overlap.Ask for a very efficient solution
//A naive method can combine the two list, and sortand apply merge interval in
//the leetcode, but is not efficient enough.
//For example,
//A: [1, 5] , [10, 14], [16, 18]
//B : [2, 6] , [8, 10], [11, 20]
//output[1, 6], [8, 20]

namespace Solution2019
{
	namespace IntervalListUnion
	{
		vector<pair<int, int>> mergeNonOverlappingIntervals(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
			int lena = a.size();
			if (lena == 0) { return b; }
			int lenb = b.size();
			if (lenb == 0) { return a; }

			int i = 0; 
			int j = 0;
			int s = INT_MIN;
			int e = INT_MIN;

			while (i < lena || j < lenb) {
				pair<int, int> cur;
				if (i >= lena) { cur = b[j]; j++; }
				else if (j >= lenb) { cur = a[i]; i++; }
				else {
					if (a[i].first < b[j].first) { cur = a[i]; i++; }
					else { cur = b[j]; j++; }
				}

				if (cur.first > e) {
					if (e != INT_MIN) { result.push_back({s, e}); }
					s = cur.first;
					e = cur.second;
				}
				else {
					e = max(e, cur.second);
				}
			}
			if (e != INT_MIN) { result.push_back({ s, e }); }
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

