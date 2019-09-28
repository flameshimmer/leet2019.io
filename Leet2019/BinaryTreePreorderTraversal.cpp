#include "stdafx.h"
//Given an n-ary tree, return the preorder traversal of its nodes' values.
//
//For example, given a 3-ary tree:
//
//Return its preorder traversal as: [1,3,5,6,2,4].
//
//
//Note:
//
//Recursive solution is trivial, could you do it iteratively?

namespace Solution2019
{
	namespace BinaryTreePreorderTraversal
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
			vector<int> preorder(Node* root) {
				vector<int> result;
				if (!root) { return result; }

				stack<Node*> s;
				s.push(root);
				while (!s.empty()) {
					Node* cur = s.top();
					s.pop();
					result.push_back(cur->val);
					reverse(cur->children.begin(), cur->children.end());
					for (Node* child : cur->children) {
						s.push(child);
					}
				}
				return result;
			}
		}
		namespace Recursive {
			void helper(Node* node, vector<int>& result) {
				if (!node) { return; }
				result.push_back(node->val);
				for (Node* child : node->children) {
					helper(child, result);
				}
			}

			vector<int> preorder(Node* root) {
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

