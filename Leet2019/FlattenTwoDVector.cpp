#include "stdafx.h"

//Design and implement an iterator to flatten a 2d vector. It should support the
//following operations: next and hasNext.
// 
//
//Example:
//Vector2D iterator = new Vector2D([[1,2],[3],[4]]);
//iterator.next(); // return 1
//iterator.next(); // return 2
//iterator.next(); // return 3
//iterator.hasNext(); // return true
//iterator.hasNext(); // return true
//iterator.next(); // return 4
//iterator.hasNext(); // return false
// 
//
//Notes:
//Please remember to RESET your class variables declared in Vector2D, as
//static/class variables are persisted across multiple test cases. Please see
//here for more details.
//You may assume that next() call will always be valid, that is, there will be at
//least a next element in the 2d vector when next() is called.
// 
//Follow up:
//As an added challenge, try to code it using only iterators in C++ or iterators
//in Java.

namespace Solution2019
{
	namespace FlattenTwoDVector
	{
		class Vector2D {
			vector<vector<int>>::iterator i;
			vector<vector<int>>::iterator iEnd;
			int j = 0;
		public:
			Vector2D(vector<vector<int>>& v) {
				i = v.begin();
				iEnd = v.end();
			}

			int next() {
				hasNext();
				int result = (*i)[j];
				j++;
				return result;
			}

			bool hasNext() {
				while (i != iEnd && j == (*i).size()) {
					i++;
					j = 0;
				}
				return i != iEnd;
			}
		};


		class Vector2DAnother {
		public:
			Vector2DAnother(vector<vector<int>>& vec2d) {
				i = vec2d.begin(), iEnd = vec2d.end();
				if (i != iEnd)
					j = i->begin();
			}

			int next() {
				hasNext();
				return *j++;
			}

			bool hasNext() {
				while (i != iEnd && j == i->end()) {
					++i;
					if (i != iEnd) { j = i->begin(); } // i has changed at this point. So need to check again. 
				}
				return i != iEnd;
			}

		private:
			vector<vector<int>>::iterator i, iEnd;
			vector<int>::iterator j;
		};


		/**
		 * Your Vector2D object will be instantiated and called as such:
		 * Vector2D* obj = new Vector2D(v);
		 * int param_1 = obj->next();
		 * bool param_2 = obj->hasNext();
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

