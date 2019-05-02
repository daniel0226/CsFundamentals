#include "yhk.h"
#include "Sorting.h"

Sorting::Sorting()
{
	values = { 5,1,6,2,3,10,4 };
	originalValues = values;
	sortMethod = 0;
	length = static_cast<int>(values.size());
}

Sorting::~Sorting()
{
	// Vector automatically gets deallocated.
}
void Sorting::verifySort()
{
	std::vector<int> sortedValues = { 1,2,3,4,5,6,10 };
	bool sorted = helperTool.equalVectors(values, sortedValues);
	if (!sorted)
	{
		std::cout << "ERROR: There was an error sorting the values." << std::endl;
	}
	else
	{
		std::cout << "SUCCESS: Vector was successfully sorted." << std::endl;
	}
}

void Sorting::beginSort()
{
	helperTool.outputVector(values, true, true);

	while (sortMethod != SortQuit)
	{
		sortMethod = helperTool.getIntInput(SortMessage, true);
		switch (sortMethod)
		{
		case INVALID_INPUT:
			std::cout << "Invalid input." << std::endl;
			break;
		case 1:
			heapSort();
			break;
		case 2:
			runMerge(0, length - 1);
			break;
		case 3:
			runQuickSort(0, length - 1);
		case 4:
			break;
		default:
			std::cout << "Invalid sorting command." << std::endl;
			break;
		}
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}

void Sorting::returnVectorValuesToOriginal()
{
	std::cout << "Reverting sorted vector to original..." << std::endl;
	values = originalValues;
	return;
}


// ----------------------------------------------------------- //
void Sorting::heapSort()
{
	// First build the heap
	// In a heap sort implementaiton, the array is generated with the root at index 0.
	// The children will be the index*2 + 1 or index*2 + 2, left or right.
	// The parent index will be (index-1)/2.
	// The way a heap is constructed, the root value is greater than it's children's value and the tree
	// is a complete tree.
	for (int i = (length / 2) - 1; i >= 0; i--)
	{
		heapify(length, i);
	}

	for (int i = length-1; i >= 0; i--)
	{
		helperTool.swap(values, 0, i);
		heapify(i, 0);
	}
	helperTool.outputVector(values, true, true);
	verifySort();
	returnVectorValuesToOriginal();
}

void Sorting::heapify(int length, int root)
{
	int largestChild = root;
	int leftChild = root * 2 + 1;
	int rightChild = root * 2 + 2;

	// If leftchild exists in vector, and if leftchild is greater than root, we switch.
	if (leftChild < length && values[leftChild] > values[largestChild])
	{
		largestChild = leftChild;
	}

	// If Rightchild exists in vector, and if rightchild is greater than current largest/
	if (rightChild < length && values[rightChild] > values[largestChild])
	{
		largestChild = rightChild;
	}

	// If the largest value is not the root
	if (largestChild != root)
	{
		helperTool.swap(values, root, largestChild);
		//Keep calling until largest child is at the root.
		heapify(length, largestChild);
	}
}


// ----------------------------------------------------------- //

void Sorting::runMerge(int start, int end)
{
	mergeSort(start, end);
	helperTool.outputVector(values, true, true);
	verifySort();
	returnVectorValuesToOriginal();
}
void Sorting::mergeSort(int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		mergeSort(start, middle);
		mergeSort(middle + 1, end);

		merge(start, middle, middle+1, end);
	}
}

void Sorting::merge(int start, int leftMiddle, int rightMiddle, int end)
{
	std::vector<int>temp;
	int firstIndex = start;

	// Compare the two array's values.
	while ((start <= leftMiddle) && (rightMiddle <= end))
	{
		if (values[start] < values[rightMiddle])
		{
			temp.push_back(values[start++]);
		}
		else
		{
			temp.push_back(values[rightMiddle++]);
		}
	}

	// If any values remain
	while (start <= leftMiddle)
	{
		temp.push_back(values[start++]);
	}
	while (rightMiddle <= end)
	{
		temp.push_back(values[rightMiddle++]);
	}

	int tempIndex = 0;
	// Update original vector
	for (int i = firstIndex; i <= end; i++)
	{
		values[i] = temp[tempIndex++];
	}

	return;
}



// ----------------------------------------------------------- //


void Sorting::runQuickSort(int start, int end)
{
	quickSort(start, end);
	helperTool.outputVector(values, true, true);
	verifySort();
	returnVectorValuesToOriginal();
}

void Sorting::quickSort(int start, int end)
{
	if (start < end)
	{
		int pivot = randomPartition(start, end);
		quickSort(start, pivot - 1);
		quickSort(pivot + 1, end);
	}
}

int Sorting::partition(int start, int end)
{
	int index = start;
	int pivot = values[end];
	
	for (int i = start; i <end; i++)
	{
		if (values[i] < pivot) {
			helperTool.swap(values, index, i);
			index++;
		}
	}

	helperTool.swap(values,index, end);
	return index;
}

int Sorting::randomPartition(int start, int end)
{
	srand((unsigned int)time(NULL));
	int random = start + (std::rand() % (end - start));
	helperTool.swap(values, random, end);
	return partition(start, end);
}
