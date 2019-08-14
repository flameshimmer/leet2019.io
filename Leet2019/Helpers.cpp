#include "stdafx.h"

bool compare_STB(int i, int j)
{
	return i < j;
}

bool compare_BTS(int i, int j)
{
	return i > j;
}

void print(int input[], int len)
{
	cout << "\nInteger array: \n";
	for (int i = 0; i < len - 1; i++)
	{
		cout << input[i] << ", ";
	}
	cout << input[len - 1] << "\n";
}

void print(unordered_set<string> set)
{
	cout << "\nSet: \n";
	int len = set.size();
	for (string s : set)
	{
		cout << s << "\n";
	}
}


void print(vector<int> input)
{
	cout << "\nVector: ";
	int inputSize = input.size();
	if (inputSize == 0) {
		cout << "\n";
		return;
	}

	for (int i = 0; i < inputSize - 1; i++)
	{
		cout << input[i] << ",";
	}
	cout << input[inputSize - 1] << "\n";
}

void print(vector<string> input)
{
	cout << "\nString Vector: \n";
	int inputSize = input.size();
	if (inputSize == 0) {
		cout << "\n";
		return;
	}

	for (int i = 0; i < inputSize - 1; i++)
	{
		cout << input[i] << "\n";
	}
	cout << input[inputSize - 1] << "\n";
}

void print(int input)
{
	cout << "integer: " << input << "\n";
}

void print(double input)
{
	cout << "double: " << input << "\n";
}

void print(string input)
{
	cout << "string: " << input << "\n";
}

void printWithSpace(string input)
{
	cout << "string with space: \n";
	for (char c : input)
	{
		if (c == ' ') { c = '.'; }
		cout << c;
	}
	cout << "\n";
}

void print(uint32_t input)
{
	cout << "Unsigned 32 bits integer: " << input << "\n";
}

void print(bool input)
{
	cout << "\nBoolean: " << (input ? "true" : "false") << "\n";
}

void printBits(uint32_t input)
{
	cout << "Binary: \n";
	for (int i = 31; i >= 0; i--)
	{
		uint32_t mask = 1 << (i);
		if (input & mask)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	cout << "\n";
}

vector<vector<char>> createMatrix(string rawInput[], int size)
{
	vector<vector<char>> input;

	for (int i = 0; i < size; i++)
	{
		vector<char> cur = vector<char>(rawInput[i].begin(), rawInput[i].end());
		input.push_back(cur);
	}
	return input;
}

void printStringMatrix(vector<string>board)
{
	cout << "String Matrix: \n";
	for (string s : board)
	{
		cout << s << "\n";
	}
	cout << "\n\n\n";
}

void print(vector<Interval> input)
{
	cout << "\Interval: ";
	int inputSize = input.size();
	if (inputSize == 0) {
		cout << "Empty \n";
		return;
	}

	for (int i = 0; i < inputSize - 1; i++)
	{
		cout << "[" << input[i].start << ", " << input[i].end << "], ";
	}
	cout << "[" << input[inputSize - 1].start << ", " << input[inputSize - 1].end << "]\n";
}

void print(vector<pair<int, int>> input)
{
	cout << "\nVector of pairs: \n";
	int inputSize = input.size();
	if (inputSize == 0) {
		cout << "\n";
		return;
	}

	for (int i = 0; i < inputSize - 1; i++)
	{
		cout << "(" << input[i].first << ", " << input[i].second << "), ";
	}
	cout << "(" << input[inputSize - 1].first << ", " << input[inputSize - 1].second << ")\n";
}


TreeNode* createTree(vector<int> data, int deliminator)
{
	int len = data.size();
	if (len == 0) { return NULL; }

	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(data[0]);
	q.push(root);
	int index = 1;
	while (!q.empty())
	{
		TreeNode* cur = q.front();
		q.pop();
		if (index == len) { break; }
		int c = data[index++];
		if (c != deliminator)
		{
			TreeNode* leftNode = new TreeNode(c);
			cur->left = leftNode;
			q.push(leftNode);
		}
		if (index == len) { break; }
		c = data[index++];
		if (c != deliminator)
		{
			TreeNode* rightNode = new TreeNode(c);
			cur->right = rightNode;
			q.push(rightNode);
		}
	}
	return root;
}


void linkTreeNodes(TreeLinkNode* root, TreeLinkNode* l, TreeLinkNode* r)
{
	if (!root) return;
	root->left = l;
	root->right = r;
}

void linkTreeNodes(TreeNode* root, TreeNode* l, TreeNode* r)
{
	if (!root) return;
	root->left = l;
	root->right = r;
}

