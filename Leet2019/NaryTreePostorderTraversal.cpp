#include "stdafx.h"
//Given an n - ary tree, return the postorder traversal of its nodes' values.
//For example, given a 3 - ary tree :
//Return its postorder traversal as : [5, 6, 3, 2, 4, 1] .
//
//Note :
//Recursive solution is trivial, could you do it iteratively ?

namespace Solution2019
{
	namespace NaryTreePostorderTraversal
	{
		class Node {
		public:
			int val;
			vector<Node*> children;

			Node() {}

			Node(int _val, vector<Node*> _children) {
				val = _val;
				children = _children;
			}
		};
		namespace Iterative {
			vector<int> postorder(Node* root) {
				vector<int> result;
				if (!root) { return result; }

				stack<Node*> s;
				s.push(root);
				while (!s.empty()) {
					Node* cur = s.top();
					s.pop();
					result.push_back(cur->val);

					for (Node* child : cur->children) {
						s.push(child);
					}
				}

				reverse(result.begin(), result.end());
				return result;
			}
		}

		namespace Recursive {
			void helper(Node* node, vector<int>& result) {
				if (!node) { return; }

				for (Node* child : node->children) {
					helper(child, result);
				}
				result.push_back(node->val);
			}

			vector<int> postorder(Node* root) {
				vector<int> result;
				helper(root, result);
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

