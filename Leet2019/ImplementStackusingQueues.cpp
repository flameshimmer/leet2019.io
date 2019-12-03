#include "stdafx.h"

//Implement the following operations of a stack using queues.
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//empty() -- Return whether the stack is empty.
//
//Example:
//MyStack stack = new MyStack();
//stack.push(1);
//stack.push(2);  
//stack.top();   // returns 2
//stack.pop();   // returns 2
//stack.empty(); // returns false
//
//Notes:
//You must use only standard operations of a queue -- which means only push to
//back, peek/pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively. You may
//simulate a queue by using a list or deque (double-ended queue), as long as you
//use only standard operations of a queue.
//You may assume that all operations are valid (for example, no pop or top
//operations will be called on an empty stack).

namespace Solution2019
{
	namespace ImplementStackusingQueues
	{
		class MyStack {
			queue<int> q;
		public:
			/** Initialize your data structure here. */
			MyStack() {

			}

			/** Push element x onto stack. */
			void push(int x) {
				q.push(x);
			}

			/** Removes the element on top of the stack and returns that element. */
			int pop() {
				queue<int> tmp;
				while (q.size() > 1) {
					tmp.push(q.front());
					q.pop();
				}
				int result = q.front();
				swap(q, tmp);
				return result;
			}

			/** Get the top element. */
			int top() {
				int result;
				queue<int> tmp;
				while (!q.empty()) {
					tmp.push(q.front());
					result = q.front();
					q.pop();
				}
				swap(q, tmp);
				return result;
			}

			/** Returns whether the stack is empty. */
			bool empty() {
				return q.empty();
			}
		};

		/**
		 * Your MyStack object will be instantiated and called as such:
		 * MyStack* obj = new MyStack();
		 * obj->push(x);
		 * int param_2 = obj->pop();
		 * int param_3 = obj->top();
		 * bool param_4 = obj->empty();
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

