#include "stdafx.h"
//You need to construct a string consists of parenthesis and
//integers from a binary tree with the preorder traversing way.
//
//The null node needs to be represented by empty parenthesis 
//pair "()". And you need to omit all the empty parenthesis
//pairs that don't affect the one-to-one mapping relationship
//between the string and the original binary tree.
//
//Example 1:
//Input: Binary tree: [1,2,3,4]
//       1
//     /   \
//    2     3
//   /    
//  4     
//
//Output: "1(2(4))(3)"
//Explanation: Originallay it needs to be "1(2(4)())(3()())", 
//but you need to omit all the unnecessary empty parenthesis pairs. 
//And it will be "1(2(4))(3)".
//
//Example 2:
//Input: Binary tree: [1,2,3,null,4]
//       1
//     /   \
//    2     3
//     \  
//      4 
//
//Output: "1(2()(4))(3)"
//Explanation: Almost the same as the first example, 
//except we can't omit the first parenthesis pair to break the 
//one-to-one mapping relationship between the input and the output.
namespace Solution2019
{
	namespace ConstructStringfromBinaryTree
	{
		string tree2str(TreeNode* t) {
			if (!t) { return ""; }
			string s = to_string(t->val);
			if (t->left) { s += "(" + tree2str(t->left) + ")"; }
			else if (t->right) { s += "()"; }

			if (t->right) { s += "(" + tree2str(t->right) + ")"; }
			return s;
		}

		string tree2strIterative(TreeNode* t) {
			if (!t) { return ""; }

			stack<TreeNode*> s;
			s.push(t);

			unordered_set<TreeNode*> visited;
			string result = "";
			while (!s.empty()) {
				TreeNode* cur = s.top();
				if (visited.count(cur) > 0) {
					s.pop();
					result += ")";
				}
				else {
					visited.insert(cur);
					result += "(" + cur->val;
					if (!cur->left && cur->right) { result += "()"; }
					if (cur->right) { s.push(cur->right); }
					if (cur->left) { s.push(cur->left); }
				}
			}
			return result.substr(1, result.size() - 1);
		}

		void Main() {
			TreeNode* test = new TreeNode(2);
			print(tree2strIterative(test));
		}
	}
}

