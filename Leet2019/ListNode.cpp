#include "stdafx.h"

//Definition for singly - linked list.
ListNode* createList(initializer_list<int> list)
{
	ListNode* head = NULL;
	ListNode* tail = NULL;
	for (int value : list)
	{
		ListNode* newNode = new ListNode(value);
		if (!head)
		{
			head = newNode;
		}
		else
		{
			tail->next = newNode;
		}
		tail = newNode;
	}
	return head;
}

void deleteList(ListNode* list)
{
	if (!list)
	{
		return;
	}
	while (list)
	{
		ListNode* next = list->next;
		delete list;
		list = next;
	}
}

ListNode* getListNodeAt(ListNode* list, int index)
{
	if (!list || index < 0){ return NULL; }

	ListNode* cur = list;
	while (cur)
	{
		if (index <= 0) { break; }
		index--;
		cur = cur->next;
	}
	return cur;
}

ListNode* getLastNode(ListNode* list)
{
	if (!list){ return NULL; }
	while (list->next)
	{
		list = list->next;
	}
	return list;
}

void print(ListNode* list)
{
	cout << "ListNode: \n";
	if (!list){ return; }
	while (list->next)
	{
		cout << list->val << " -> ";
		list = list->next;
	}
	cout << list->val << "\n";
}

void print(vector<ListNode*> list)
{
	cout << "vector of ListNode: \n";
	if (list.empty()) { cout << "Empty vector!!!\n"; return; }
	for (ListNode* n : list) {
		print(n);
	}
}


ListNode* createListWithCycle(initializer_list<int> listValue, int indexPointFrom, int indexPointTo)
{
	ListNode* list = createList(listValue);
	ListNode* nodeAtPointFrom = getListNodeAt(list, indexPointFrom);
	ListNode* nodeAtPointTo = getListNodeAt(list, indexPointTo);
	nodeAtPointFrom->next = nodeAtPointTo;
	return list;
}


