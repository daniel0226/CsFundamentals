#include "yhk.h"
#include "Sorting.h"

Sorting sortObj;
yhk helperTools;

void runCommand(int command);

int main(int argc, char*argv[])
{
	runCommand(helperTools.getIntInput(MESSAGE, false));
	helperTools.keepCommandPromptOpen();
}

void runCommand(int command)
{
	switch (command)
	{
	case 0:
		std::cout << "Invalid command." << std::endl;
		exit(EXIT_SUCCESS);
	case 1:
		sortObj.beginSort();
	}
}
