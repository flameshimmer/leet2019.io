#include "stdafx.h"
//Some people will make friend requests. The list of 
//their ages is given and ages[i] is the age of the 
//ith person. 
//
//Person A will NOT friend request person B (B != A)
//if any of the following conditions are true:
//
//age[B] <= 0.5 * age[A] + 7
//age[B] > age[A]
//age[B] > 100 && age[A] < 100
//Otherwise, A will friend request B.
//
//Note that if A requests B, B does not necessarily 
//request A.  Also, people will not friend request themselves.
//
//How many total friend requests are made?
//
//Example 1:
//Input: [16,16]
//Output: 2
//Explanation: 2 people friend request each other.
//
//Example 2:
//Input: [16,17,18]
//Output: 2
//Explanation: Friend requests are made 17 -> 16, 18 -> 17.
//
//Example 3:
//Input: [20,30,100,110,120]
//Output: 
//Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
// 
//Notes:
//1 <= ages.length <= 20000.
//1 <= ages[i] <= 120. 

namespace Solution2019
{
	namespace FriendsOfAppropriateAges
	{
		int numFriendRequests(vector<int>& ages) {
			int a[121] = {};
			int result = 0;
			for (int v : ages) { a[v]++; }

			int sum[121] = {};
			sum[0] = a[0];
			for (int i = 1; i <= 120; i++) {
				sum[i] = sum[i - 1] + a[i];
			}

			for (int i = 15; i <= 120; i++) {
				int count = sum[i] - sum[i / 2 + 7];
				result += count * a[i] - a[i];
			}
			return result;
		}

		int numFriendRequestsAnother(vector<int>& ages) {
			int a[121] = {};
			int result = 0;
			for (int v : ages) { a[v]++; }

			for (int i = 15; i <= 120; i++) {
				for (int j = 0.5 * i + 8; j <= i; j++) {
					result += a[j] * (a[i] - (i == j));
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

