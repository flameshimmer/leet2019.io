#include "stdafx.h"

//After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
//We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
//We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
//We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
//We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
//We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
//We reveal 13, and move 17 to the bottom.  The deck is now [17].
//We reveal 17.
//Since all the cards revealed are in increasing order, the answer is correct.
// 
//
//Note:
//
//1 <= A.length <= 1000
//1 <= A[i] <= 10^6
//A[i] != A[j] for all i != j



namespace Solution2019
{
	namespace RevealCardsInIncreasingOrder
	{
		vector<int> deckRevealedIncreasing(vector<int>& deck) {
			sort(deck.rbegin(), deck.rend());
			deque<int> d;
			d.push_back(deck[0]);
			for (int i = 1; i < deck.size(); i++) {
				d.push_front(d.back());
				d.pop_back();
				d.push_front(deck[i]);
			}
			vector<int> result(d.begin(), d.end());
			return result;
		}

		void Main() {
			vector<int> test = { 2,13,3,11,5,17,7 };
			print(deckRevealedIncreasing(test));
		}
	}
}

