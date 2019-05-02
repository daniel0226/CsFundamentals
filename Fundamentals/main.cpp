#include "yhk.h"
#include "Sorting.h"
#include "LinkedList.h"
#include "Algorithms.h"
#include "BinarySearchTree.h"

Sorting sortObj;
LinkedList listObj;
Algorithms algObj;
BST bstObj;
yhk helperTools;

void runCommand(int command);

int main(int argc, char*argv[])
{
	runCommand(START_COMMANDS);
	helperTools.keepCommandPromptOpen();
}

void runCommand(int command)
{
	while (command != QUIT)
	{
		command = helperTools.getIntInput(MAIN_MESSAGE, false);
		switch (command)
		{
		case INVALID_INPUT:
			std::cout << "Invalid command." << std::endl;
			break;
		case QUIT:
			std::cout << "Exiting program..." << std::endl;
			exit(EXIT_SUCCESS);
		case 1:
			sortObj.beginSort();
			break;
		case 2:
			listObj.beginList();
			break;
		case 3:

			break;
		case 4:
			algObj.beginAlgorithms();
		}

		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}
