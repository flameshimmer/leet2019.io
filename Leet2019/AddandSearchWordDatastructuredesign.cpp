#include "stdafx.h"

//Design a data structure that supports the following two operations:
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string
//containing only letters a-z or .. A . means it can represent any one letter.
//
//Example:
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//
//Note:
//You may assume that all words are consist of lowercase letters a-z. 

namespace Solution2019
{
	namespace AddandSearchWordDatastructuredesign
	{
		class WordDictionary {
		private:
			struct Node {
				vector<Node*> children;
				bool isEnd;
				Node() {
					isEnd = false;
					children.resize(26, nullptr);
				}
			};
			Node* root;
		public:
			/** Initialize your data structure here. */
			WordDictionary() {
				root = new Node();
			}

			/** Adds a word into the data structure. */
			void addWord(string word) {
				Node* cur = root;
				for (char c : word) {
					if (cur->children[c - 'a'] == nullptr) {
						cur->children[c - 'a'] = new Node();
					}
					cur = cur->children[c - 'a'];
				}
				cur->isEnd = true;
			}

			bool helper(string& s, int start, Node* node) {
				if (start == s.size()) { return node->isEnd; }
				if (s[start] != '.') {
					return node->children[s[start] - 'a'] && helper(s, start + 1, node->children[s[start] - 'a']);
				}
				else {
					for (int i = 0; i < 26; i++) {
						if (node->children[i]) {
							if (helper(s, start + 1, node->children[i])) { return true; }
						}
					}
					return false;
				}
			}

			/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
			bool search(string word) {
				return helper(word, 0, root);
			}
		};

		/**
		 * Your WordDictionary object will be instantiated and called as such:
		 * WordDictionary* obj = new WordDictionary();
		 * obj->addWord(word);
		 * bool param_2 = obj->search(word);
		 */
		void Main() {
			WordDictionary* obj = new WordDictionary();
			obj->addWord("bad");
			obj->addWord("dad");
			obj->addWord("mad");
			bool param_2 = obj->search("pad");
			param_2 = obj->search("bad");
			param_2 = obj->search(".ad");
			param_2 = obj->search("b..");
		}
	}
}

