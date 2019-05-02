#pragma once
#ifndef Algorithms_H
#include "yhk.h"
#include "ListNode.h"
#include "LinkedList.h"
#include "TreeNode.h"
#include "BinarySearchTree.h"

#define Algorithms_COMMAND "0: Quit, 1: Lists, 2: Trees"
#define ALGO_LISTS_COMMANDS "0: QUIT, 1: Print List, 2: Remove N'th Node, 3: Reverse List, "

class Algorithms
{
public:
	Algorithms();
	void beginAlgorithms();

	//Lists
	void generateList();
	void runLinkedList();
	void removeNthNode();
	void reverseList();
	void revertListToOriginal();

private:
	int command = START_COMMANDS;
	int list_Command = START_COMMANDS;
	int listLength;
	yhk helperTool;
	LinkedList list;
	LinkedList listCopy;
	BST tree;
};

#endif