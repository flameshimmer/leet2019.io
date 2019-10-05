// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include <limits> // for printing double
#include <complex> // for math abs
#include <queue> // for priority queue
#include <utility> // for make_pair
#include <deque> // for double ended queue

#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <initializer_list>
#include <cMath>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <stdint.h>
#include <climits>
#include <bitset>
using namespace std;

// Template helper functions
template <class T>
vector<T> createVector(std::initializer_list<T> list)
{
	vector<T> myVector;
	for (auto elem : list)
	{
		myVector.push_back(elem);
	}
	return myVector;
}

template <class T>
void print(vector<vector<T>> input)
{
	cout << "\nMatrix: \n";
	if (input.size() == 0) { cout << "Empty!!! \n"; return; }
	string div = "";
	for (unsigned int i = 0; i < input[0].size(); i++)
	{
		div += "-----";
	}
	div += '-';
	cout << div << "\n";
	for (vector<T> v : input)
	{
		for (unsigned int i = 0; i < v.size(); i++)
		{
			cout << "| " << setw(2) << v[i] << " ";
		}
		cout << "|\n";
		cout << div << "\n";
	}
}

// helper class
// List Node
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* createList(initializer_list<int> list);
ListNode* getListNodeAt(ListNode* list, int index);
ListNode* getLastNode(ListNode* list);
void deleteList(ListNode* list);
void print(ListNode* list);
ListNode* createListWithCycle(initializer_list<int> listValue, int indexPointFrom, int indexPointTo);

// RandomListNode
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//Definition for binary tree node
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for linked binary tree node
struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//Definition for undirected graph.
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

//Definition for a point.
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

//Defind for a node
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

// Helper functions
// int
bool compare_STB(int i, int j);
bool compare_BTS(int i, int j);
void print(int input[], int len);
void print(vector<int> input);
void print(int input);

// unsigned int
void print(uint32_t input);

// double
void print(double input);

// boolean
void print(bool input);

// string
void print(vector<string> input);
void print(string input);
void printWithSpace(string input);

// intervals
void print(vector<Interval> input);

// pairs
void print(vector<pair<int, int>> input);

// bits
void printBits(uint32_t input);

// matrix
void printStringMatrix(vector<string>board);
vector<vector<char>> createMatrix(string rawInput[], int size);

// trees
vector<int> getFlattenedTreeData(TreeNode* root);
TreeNode* createTree(vector<int> data, int deliminator);
void linkTreeNodes(TreeNode* root, TreeNode* l, TreeNode* r);
void linkTreeNodes(TreeLinkNode* root, TreeLinkNode* l, TreeLinkNode* r);

// decode tree and pretty print
TreeNode* ReadBinaryTree(vector<string>& treeData, int& index);
int printTree(TreeNode* root);
int printTree(vector<string>& treeData);
TreeNode* ReadBinaryTree(vector<string>& treeData);

// set
void print(unordered_set<string> set);
