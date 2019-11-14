#include "stdafx.h"

//We want to use quad trees to store an N x N boolean grid. Each cell in the grid
//can only be true or false. The root node represents the whole grid. For each
//node, it will be subdivided into four children nodes until the values in the
//region it represents are all the same.
//Each node has another two boolean attributes : isLeaf and val. isLeaf is true
//if and only if the node is a leaf node. The val attribute for a leaf node
//contains the value of the region it represents.
//Your task is to use a quad tree to represent a given grid. The following
//example may help you understand the problem better:
//Given the 8 x 8 grid below, we want to construct the corresponding quad tree:
//It can be divided according to the definition above:
// 
//The corresponding quad tree should be as following, where each node is
//represented as a (isLeaf, val) pair.
//For the non-leaf nodes, val can be arbitrary, so it is represented as *.
//
//Note:
//N is less than 1000 and guaranteened to be a power of 2.
//If you want to know more about the quad tree, you can refer to its wiki. 

namespace Solution2019
{
	namespace ConstructQuadTree
	{

		// Definition for a QuadTree node.
		class Node {
		public:
			bool val;
			bool isLeaf;
			Node* topLeft;
			Node* topRight;
			Node* bottomLeft;
			Node* bottomRight;

			Node() {}

			Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
				val = _val;
				isLeaf = _isLeaf;
				topLeft = _topLeft;
				topRight = _topRight;
				bottomLeft = _bottomLeft;
				bottomRight = _bottomRight;
			}
		};


		Node* helper(vector<vector<int>>& grid, int x, int y, int len) {
			if (len == 1) {
				return new Node(grid[x][y], true, nullptr, nullptr, nullptr, nullptr);
			}

			Node* result = new Node(0, false, nullptr, nullptr, nullptr, nullptr);
			Node* topLeft = helper(grid, x, y, len / 2);
			Node* topRight = helper(grid, x, y + len / 2, len / 2);
			Node* bottomLeft = helper(grid, x + len / 2, y, len / 2);
			Node* bottomRight = helper(grid, x + len / 2, y + len / 2, len / 2);

			if (topLeft->isLeaf &&
				topRight->isLeaf &&
				bottomLeft->isLeaf &&
				bottomRight->isLeaf &&
				topLeft->val == topRight->val &&
				topRight->val == bottomLeft->val &&
				bottomLeft->val == bottomRight->val) {
				result->isLeaf = true;
				result->val = topLeft->val;
			}
			else {
				result->topLeft = topLeft;
				result->topRight = topRight;
				result->bottomLeft = bottomLeft;
				result->bottomRight = bottomRight;
			}
			return result;
		}

		Node* construct(vector<vector<int>>& grid) {
			return helper(grid, 0, 0, grid.size());
		}

		void Main() {
			vector<vector<int>> test = { {1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0} };
			construct(test);
		}
	}
}

