#include "stdafx.h"
// 

namespace Solution2019
{
	namespace SerializeandDeserializeNaryTree
	{
		// Definition for a Node.
		class Node {
		public:
			int val = NULL;
			vector<Node*> children;

			Node() {}

			Node(int _val, vector<Node*> _children) {
				val = _val;
				children = _children;
			}
		};

		class Codec {
			//rule:  root, number of child, each child
			void serializeHelper(Node* root, string& s) {
				if (!root) { return; }
				s += " " + to_string(root->val) + " " + to_string(root->children.size());
				for (Node* child : root->children) {
					serializeHelper(child, s);
				}
			}

			Node* deserializeHelper(istringstream& ss) {
				ss.peek();
				if (ss.eof()) { return nullptr; }

				Node* newNode = new Node();
				int childCount = 0;
				ss >> newNode->val >> childCount;
				for (int i = 0; i < childCount; i++) {
					newNode->children.push_back(deserializeHelper(ss));
				}
				return newNode;
			}

		public:
			// Encodes a tree to a single string.
			string serialize(Node* root) {
				string result;
				serializeHelper(root, result);
				return result;
			}

			// Decodes your encoded data to tree.
			Node* deserialize(string data) {
				istringstream ss(data);
				return deserializeHelper(ss);
			}
		};

		class CodecAnother {
			//rule:  1 [3[5 6] 2 4]
			string serializeHelper(Node* root) {
				if (!root) { return ""; }

				string result = to_string(root->val);
				if (root->children.empty()) { return result; }

				result += '[';
				for (Node* child : root->children) {
					result += serializeHelper(child) + " ";
				}
				result.pop_back();
				result += ']';
				return result;
			}

		public:

			// Encodes a tree to a single string.
			string serialize(Node* root) {
				return serializeHelper(root);
			}

			// Decodes your encoded data to tree.
			Node* deserialize(string data) {
				if (data.empty()) { return nullptr; }
				stack<Node*> s;
				for (int i = 0; i < data.size(); i++) {
					if (isdigit(data[i])) {
						int val = 0;
						while (isdigit(data[i])) {
							val = val * 10 + (data[i] - '0');
							i++;
						}
						i--;
						s.push(new Node(val, vector<Node*>()));
					}
					else if (data[i] == '[') { s.push(nullptr); }
					else if (data[i] == ']') {
						stack<Node*> tmp;
						while (s.top() != nullptr) {
							tmp.push(s.top());
							s.pop();
						}
						s.pop();
						Node* r = s.top();
						while (!tmp.empty()) {
							r->children.push_back(tmp.top());
							tmp.pop();
						}
					}
				}
				return s.top();
			}
		};


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

