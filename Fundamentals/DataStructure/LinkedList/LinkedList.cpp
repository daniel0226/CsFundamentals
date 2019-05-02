#include "yhk.h"
#include "ListNode.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{
	length = 0;
	head = NULL;
}

LinkedList::~LinkedList()
{
	ListNode *next = head;
	while (next != NULL)
	{
		ListNode *deleteNode = next;
		next = next->next;
		delete deleteNode;
	}
}

void LinkedList::beginList()
{
	printList();
	while (command != QUIT)
	{
		int commandOption = helperTool.getIntInput(LIST_COMMANDS, true);
		switch (commandOption)
		{
		case QUIT:
			return;
		case INVALID_INPUT:
			std::cout << "Invalid input." << std::endl;
			break;
		case 1:
			insert(helperTool.getIntInput(LIST_MESSAGE, true));
			break;
		case 2:
			deleteVal();
			break;
		case 3:
			printList();
			break;
		case 4:
			std::cout << "Linked List length is: " << getLength() << std::endl;
			break;
		default:
			std::cout << "Invalid linked list command." << std::endl;
		}

		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}

// -------------------------------------------------------- // 
void LinkedList::insert(int val)
{
	ListNode *newNode = new ListNode(val);
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		ListNode *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	length++;
}

void LinkedList::deleteVal()
{
	int valToDelete = helperTool.getIntInput(LIST_DELETE, true);
	ListNode *temp = head;
	ListNode *slow = new ListNode(0);
	slow->next = head;
	ListNode *ans = slow;

	if (head == NULL)
	{
		std::cout << "List is currently empty. Cannot delete." << std::endl;
		return;
	}
	
	while (temp != NULL)
	{
		if (temp->val == valToDelete)
		{
			slow->next = temp->next;
			head = ans->next;
			length--;
			return;
		}
		else
		{
			temp = temp->next;
			slow = slow->next;
		}
	}

	std::cout << "Could not find value: " << valToDelete << " in linked list." << std::endl;
	return;

}

ListNode* LinkedList::getList()
{
	return head;
}
void LinkedList::setList(ListNode* list)
{
	head = clone(list);
}

ListNode* LinkedList::clone(ListNode* list)
{
	if (list == NULL)
	{
		return NULL;
	}

	ListNode *copy = new ListNode(list->val);
	copy->next = clone(list->next);
	return copy;
}


void LinkedList::printList()
{
	if (head == NULL)
	{
		std::cout << "List is currently empty!" << std::endl;
		return;
	}

	ListNode *temp = head;
	while (temp != NULL)
	{
		std::cout << temp->val << "->";
		temp = temp->next;
	}
	std::cout << "null" << std::endl;
	NEWLINE
}

int LinkedList::getLength() const
{
	return length;
}