#include "stdafx.h"
/*Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the 
longest path from the root node down to the farthest
leaf node.

For example, given a 3-ary tree:
We should return its max depth, which is 3.

Note:
The depth of the tree is at most 1000.
The total number of nodes is at most 5000.*/ 

namespace Solution2019
{
	namespace MaximumDepthofNaryTree
	{
		namespace IterativeBFS {
			int maxDepth(Node* root) {
				if (!root) { return 0; }
				queue<Node*> q;
				q.push(root);

				int result = 0;
				while (!q.empty()) {
					int sz = q.size();
					while (sz) {
						sz--;
						Node* n = q.front();
						q.pop();
						for (Node* child : n->children) {
							q.push(child);
						}
					}
					result++;
				}
				return result;
			}
		}
		namespace RecursiveDFS {
			int maxDepth(Node* root) {
				if (!root) { return 0; }
				if (root->children.size() == 0) { return 1; }

				int maxD = 0;
				for (Node* n : root->children) {
					maxD = max(maxD, maxDepth(n));
				}
				return maxD + 1;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

