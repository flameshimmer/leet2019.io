#include "stdafx.h"
//Design a stack that supports push, pop, top, and 
//retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
// 
//
//Example:
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns -3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns -2.

namespace Solution2019
{
	namespace MinStack
	{
		class MinStack {
		private:
			vector<pair<int, int>> data;
			int minV;
		public:
			/** initialize your data structure here. */
			MinStack() {
				minV = INT_MAX;
			}

			void push(int x) {
				minV = min(minV, x);
				data.push_back(make_pair(x, minV));
			}

			void pop() {
				if (!data.empty()) {
					data.pop_back();
					minV = data.empty() ? INT_MAX : data.back().second;
				}
			}

			int top() {
				if (data.empty()) { return -1; }
				return data.back().first;
			}

			int getMin() {
				if (data.empty()) { return -1; }
				return data.back().second;
			}
		};

		/**
		 * Your MinStack object will be instantiated and called as such:
		 * MinStack* obj = new MinStack();
		 * obj->push(x);
		 * obj->pop();
		 * int param_3 = obj->top();
		 * int param_4 = obj->getMin();
		 */
		void Main() {
			MinStack* obj = new MinStack();
			obj->push(2147483646);
			obj->push(2147483646);
			obj->push(2147483647);
			int param_3 = obj->top();
			obj->pop();
			int param_4 = obj->getMin();
			obj->pop();
			param_4 = obj->getMin();
			obj->pop();
			obj->push(2147483647);
			param_3 = obj->top();
			param_4 = obj->getMin();
			obj->push(INT_MIN);
			param_3 = obj->top();
			param_4 = obj->getMin();
			obj->pop();
			param_4 = obj->getMin();
		}
	}
}

