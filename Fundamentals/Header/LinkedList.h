#pragma once
#ifndef LinkedList_H
#include "ListNode.h"
#include "yhk.h"

#define LIST_COMMANDS "0: Quit, 1: Insert, 2: Delete, 3: Print, 4: Length"
#define LIST_DELETE "Value to delete: "

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void insert(int val);
	void beginList();
	void printList();
	void deleteVal();
	int getLength() const;
	ListNode* getList();
	void setList(ListNode* list);
	ListNode* clone(ListNode* list);

private:
	ListNode *head;
	yhk helperTool;
	int length;
	int command = START_COMMANDS;
};

#endif
