#include "stdafx.h"

//Implement the following operations of a queue using stacks.
//push(x) -- Push element x to the back of queue.
//pop() -- Removes the element from in front of queue.
//peek() -- Get the front element.
//empty() -- Return whether the queue is empty.
//
//Example:
//MyQueue queue = new MyQueue();
//queue.push(1);
//queue.push(2);  
//queue.peek();  // returns 1
//queue.pop();   // returns 1
//queue.empty(); // returns false
//
//Notes:
//You must use only standard operations of a stack -- which means only push to
//top, peek/pop from top, size, and is empty operations are valid.
//Depending on your language, stack may not be supported natively. You may
//simulate a stack by using a list or deque (double-ended queue), as long as you
//use only standard operations of a stack.
//You may assume that all operations are valid (for example, no pop or peek
//operations will be called on an empty queue).

namespace Solution2019
{
	namespace ImplementQueueusingStacks
	{
		class MyQueue {
			stack<int> spush;
			stack<int> spop;
		public:
			/** Initialize your data structure here. */
			MyQueue() {

			}

			/** Push element x to the back of queue. */
			void push(int x) {
				if (spop.size() > spush.size()) {
					while (!spop.empty()) { spush.push(spop.top()); spop.pop(); }
				}
				spush.push(x);
			}

			/** Removes the element from in front of queue and returns that element. */
			int pop() {
				int result = peek();
				spop.pop();
				return result;
			}

			/** Get the front element. */
			int peek() {
				if (spush.size() > spop.size()) {
					while (!spush.empty()) { spop.push(spush.top()); spush.pop(); }
				}
				return spop.top();
			}

			/** Returns whether the queue is empty. */
			bool empty() {
				return spush.empty() && spop.empty();
			}
		};

		/**
		 * Your MyQueue object will be instantiated and called as such:
		 * MyQueue* obj = new MyQueue();
		 * obj->push(x);
		 * int param_2 = obj->pop();
		 * int param_3 = obj->peek();
		 * bool param_4 = obj->empty();
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

