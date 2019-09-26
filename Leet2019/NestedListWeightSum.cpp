#include "stdafx.h"
//Given a nested list of integers, return the sum of all 
//integers in the list weighted by their depth.
//
//Each element is either an integer, or a list -- whose 
//elements may also be integers or other lists.
//
//Example 1:
//
//Input: [[1,1],2,[1,1]]
//Output: 10 
//Explanation: Four 1's at depth 2, one 2 at depth 1.
//Example 2:
//
//Input: [1,[4,[6]]]
//Output: 27 
//Explanation: One 1 at depth 1, one 4 at depth 2, 
//and one 6 at depth 3; 1 + 4*2 + 6*3 = 27. 

namespace Solution2019
{
	namespace NestedListWeightSum
	{
		/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
		/*
		void helper(vector<NestedInteger>& list, int depth, int& result) {
			for (NestedInteger i : list) {
				if (i.isInteger()) { result += i.getInteger() * depth; }
				else {
					helper(i.getList(), depth + 1, result);
				}
			}
		}

		int depthSum(vector<NestedInteger>& nestedList) {
			int result = 0;
			helper(nestedList, 1, result);
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
		*/


		namespace iterative {
		/*
		    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for (NestedInteger ni: nestedList) {q.push(ni);}
        int result = 0;
        int depth = 1;
        while(!q.empty()) {
            int curQueueSize = q.size();            
            while(curQueueSize > 0) {
                NestedInteger cur = q.front();
                q.pop(); 
                if (cur.isInteger()) {result += depth * cur.getInteger();}
                else {
                    for (NestedInteger n : cur.getList()) {
                        q.push(n);
                    }
                }
                curQueueSize--;
            }
            depth++;
        }
        return result;
    }
		*/
		}
	}
}

