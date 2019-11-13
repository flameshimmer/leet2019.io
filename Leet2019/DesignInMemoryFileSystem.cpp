#include "stdafx.h"

//Design an in-memory file system to simulate the following functions:
//ls: Given a path in string format. If it is a file path, return a list that
//only contains this file's name. If it is a directory path, return the list of
//file and directory names in this directory. Your output (file and directory
//names together) should in lexicographic order.
//mkdir: Given a directory path that does not exist, you should make a new
//directory according to the path. If the middle directories in the path don't
//exist either, you should create them as well. This function has void return
//type.
//addContentToFile: Given a file path and file content in string format. If the
//file doesn't exist, you need to create that file containing given content. If
//the file already exists, you need to append given content to original content.
//This function has void return type.
//readContentFromFile: Given a file path, return its content in string format.
// 
//
//Example:
//Input: 
//["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
//[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
//Output:
//[null,[],null,null,["a"],"hello"]
//Explanation:
//filesystem
// 
//
//Note:
//You can assume all file or directory paths are absolute paths which begin with
/// and do not end with / except that the path is just "/".
//You can assume that all operations will be passed valid parameters and users
//will not attempt to retrieve file content or list a directory or file that does
//not exist.
//You can assume that all directory names and file names only contain lower-case
//letters, and same names won't exist in the same directory. 

namespace Solution2019
{
	namespace DesignInMemoryFileSystem
	{
		class FileSystem {

		private:
			struct Node {
				bool isFile;
				string content;
				unordered_map<string, Node*> children;
				Node() : isFile(false) {}
			};
			Node* root;

			vector<string> getStrs(string& path) {
				vector<string> result;
				istringstream ss(path);
				string cur;
				while (getline(ss, cur, '/')) {
					if (!cur.empty()) { ///-> Note that cur can be empty here with getLine!!! 
						result.push_back(cur);
					}
				}
				return result;
			}

		public:
			FileSystem() {
				root = new Node();
			}

			vector<string> ls(string path) {
				vector<string> strs = getStrs(path);
				Node* cur = root;
				for (string s : strs) {
					cur = cur->children[s];
				}
				if (cur->isFile) { return { strs.back() }; }

				vector<string> result;
				for (auto& p : cur->children)
				{
					result.push_back(p.first);
				}
				sort(result.begin(), result.end());
				return result;
			}

			void mkdir(string path) {
				vector<string> strs = getStrs(path);
				Node* cur = root;
				for (string s : strs) {
					if (cur->children.find(s) == cur->children.end()) {
						cur->children[s] = new Node();
					}
					cur = cur->children[s];
				}
			}

			void addContentToFile(string filePath, string content) {
				vector<string> strs = getStrs(filePath);
				Node* cur = root;
				for (string s : strs) {
					if (cur->children.find(s) == cur->children.end()) {
						cur->children[s] = new Node();
					}
					cur = cur->children[s];
				}
				cur->isFile = true;
				cur->content += content;
			}

			string readContentFromFile(string filePath) {
				vector<string> strs = getStrs(filePath);
				Node* cur = root;
				for (string s : strs) {
					cur = cur->children[s];
				}
				return cur->content;
			}
		};

		/**
		 * Your FileSystem object will be instantiated and called as such:
		 * FileSystem* obj = new FileSystem();
		 * vector<string> param_1 = obj->ls(path);
		 * obj->mkdir(path);
		 * obj->addContentToFile(filePath,content);
		 * string param_4 = obj->readContentFromFile(filePath);
		 */

		void Main() {
			FileSystem* obj = new FileSystem();
			vector<string> param_1 = obj->ls("/");
			obj->mkdir("/a/b/c");
			obj->addContentToFile("/a/b/c/d", "hello");
			param_1 = obj->ls("/");
			string param_4 = obj->readContentFromFile("/a/b/c/d");
		}
	}
}

