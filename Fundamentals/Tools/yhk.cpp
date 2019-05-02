#include "yhk.h"

int yhk::getIntInput(std::string message, bool newLine)
{
	int numInput{ 0 };
	std::cout << message << std::endl;
	std::cout << "INPUT: ";

	if (!(std::cin >> numInput))
	{
		return INVALID_INPUT;
	}
	else
	{
		if (newLine)
		{
			std::cout << std::endl;
		}
		return numInput;
	}

}
void yhk::outputVector(std::vector<int> arr, bool newLine, bool outputStatement)
{
	int length = static_cast<int>(arr.size());
	if (outputStatement)
	{
		std::cout << "Current vector values: ";
	}

	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
	if (newLine)
	{
		std::cout << std::endl;
	}

	return;
}

void yhk::swap(std::vector<int> &vec, int firstIndex, int secondIndex)
{
	int temp = vec[firstIndex];
	vec[firstIndex] = vec[secondIndex];
	vec[secondIndex] = temp;
	return;
}

void yhk::keepCommandPromptOpen()
{
	system("pause");
}

bool yhk::equalVectors(std::vector<int> vec1, std::vector<int> vec2)
{
	bool equal = true;

	int length1 = static_cast<int>(vec1.size());
	int length2 = static_cast<int>(vec2.size());

	equal = (length1 == length2);
	if (!equal)
	{
		return equal;
	}
	else 
	{
		for (int i = 0; i < length1; i++)
		{
			if (vec1[i] != vec2[i])
			{
				equal = false;
				break;
			}
		}
	}
	return equal;
}