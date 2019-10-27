#include "stdafx.h"
//Design a max stack that supports push, pop, top, peekMaxand popMax.
//
//push(x) --Push element x onto stack.
//pop() --Remove the element on top of the stackand return it.
//top() --Get the element on the top.
//peekMax() --Retrieve the maximum element in the stack.
//popMax() --Retrieve the maximum element in the stack, and remove it.
//If you find more than one maximum elements, only remove the top - most one.
//
//Example 1:
//MaxStack stack = new MaxStack();
//stack.push(5);
//stack.push(1);
//stack.push(5);
//stack.top(); -> 5
//stack.popMax(); -> 5
//stack.top(); -> 1
//stack.peekMax(); -> 5
//stack.pop(); -> 1
//stack.top(); -> 5
//
//Note:
//-1e7 <= x <= 1e7
//Number of operations won't exceed 10000.
//The last four operations won't be called when stack is empty. 

namespace Solution2019
{
	namespace MaxStack
	{
		namespace UseTwoStacks {
			class MaxStack {
			private:
				stack<int> data;
				stack<int> max;

				void addMax(int x) {
					if (max.empty() || x >= max.top()) {
						max.push(x);
					}
				}
			public:
				/** initialize your data structure here. */
				MaxStack() {

				}

				void push(int x) {
					data.push(x);
					addMax(x);
				}

				int pop() {
					int result = data.top();
					data.pop();
					if (result == max.top()) {
						max.pop();
					}
					return result;
				}

				int top() {
					return data.top();
				}

				int peekMax() {
					return max.top();
				}

				int popMax() {
					int result = max.top();

					stack<int> tmp;
					while (data.top() != result) {
						tmp.push(data.top());
						data.pop();
					}
					data.pop();
					max.pop();
					while (!tmp.empty()) {
						data.push(tmp.top());
						addMax(tmp.top()); //----> don't forget to re-establish max!!!!
						tmp.pop();
					}
					return result;
				}
			};
		}

		namespace UseListAndHashMap {

			class MaxStack {
				list<int> data;
				map<int, vector<list<int>::iterator>> myMap;
			public:
				/** initialize your data structure here. */
				MaxStack() {

				}

				void push(int x) {
					data.push_front(x);
					myMap[x].push_back(data.begin());
				}

				int pop() {
					int result = data.front();
					myMap[result].pop_back();
					if (myMap[result].empty()) { myMap.erase(result); }
					data.pop_front();
					return result;
				}

				int top() {
					return data.front();
				}

				int peekMax() {
					return myMap.rbegin()->first;
				}

				int popMax() {
					int result = myMap.rbegin()->first;
					auto it = myMap.rbegin()->second.back();
					myMap.rbegin()->second.pop_back();
					if (myMap.rbegin()->second.empty()) { myMap.erase(result); }
					data.erase(it);
					return result;
				}
			};
		}

		/**
		 * Your MaxStack object will be instantiated and called as such:
		 * MaxStack* obj = new MaxStack();
		 * obj->push(x);
		 * int param_2 = obj->pop();
		 * int param_3 = obj->top();
		 * int param_4 = obj->peekMax();
		 * int param_5 = obj->popMax();
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

