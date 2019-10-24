#include "stdafx.h"
// 

namespace Solution2019
{
	namespace SerializeandDeserializeBST
	{
		void serializeImpl(TreeNode* root, string& s) {
			if (!root) { return; }
			s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
			serializeImpl(root->left, s);
			serializeImpl(root->right, s);
		}

		TreeNode* deserializeImpl(string& s, int& pos, int curMin, int curMax) {
			if (pos >= s.size()) { return nullptr; }
			int val = *reinterpret_cast<const int*>(s.data() + pos);
			if (val < curMin || val > curMax) {
				return nullptr;
			}
			pos += sizeof(val);
			TreeNode* newNode = new TreeNode(val);
			newNode->left = deserializeImpl(s, pos, curMin, val);
			newNode->right = deserializeImpl(s, pos, val, curMax);
			return newNode;
		}


		string serialize(TreeNode* root) {
			string s;
			serializeImpl(root, s);
			return s;
		}

		TreeNode* deserialize(string data) {
			int pos = 0;
			return deserializeImpl(data, pos, INT_MIN, INT_MAX);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

