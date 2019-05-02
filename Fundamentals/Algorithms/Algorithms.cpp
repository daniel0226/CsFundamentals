#include "yhk.h"
#include "ListNode.h"
#include "LinkedList.h"
#include "TreeNode.h"
#include "Algorithms.h"
#include "BinarySearchTree.h"

Algorithms::Algorithms()
{
	listLength = 10;
}

void Algorithms::beginAlgorithms()
{
	while (command != QUIT) 
	{
		int command = helperTool.getIntInput(Algorithms_COMMAND, true);
		switch (command)
		{
		case QUIT:
			return;
		case 1:
			runLinkedList();
			break;
		}
	}
}

void Algorithms::runLinkedList()
{
	generateList();
	while (list_Command != QUIT)
	{
		
		int command = helperTool.getIntInput(ALGO_LISTS_COMMANDS, true);
		switch (command)
		{
		case QUIT:
			return;
		case 1:
			list.printList();
		case 2:
			removeNthNode();
			break;
		case 3:
			reverseList();
			break;
		default:
			std::cout << "Invalid list algorithm command." << std::endl;
			break;
		}
	}
}

void Algorithms::removeNthNode()
{
	list.printList();
	revertListToOriginal();
}

void Algorithms::reverseList()
{
	//1->2->3->4
	//      ^
	//2->1->NULL
	ListNode *prev = NULL;
	ListNode *head = list.getList();
	while (head != NULL)
	{
		ListNode *next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	list.setList(prev);
	list.printList();
	revertListToOriginal();
}

void Algorithms::revertListToOriginal()
{
	std::cout << "Reverting list back to original..." << std::endl;
	list.setList(listCopy.getList());
}

void Algorithms::generateList()
{
	for (int i = 0; i <= listLength; i++)
	{
		list.insert(i);
		listCopy.insert(i);
	}
	return;
}