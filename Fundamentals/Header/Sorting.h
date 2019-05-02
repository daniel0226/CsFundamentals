#include "yhk.h"

#define SortMessage "1: HeapSort, 2: MergeSort, 3: QuickSort, 4:Quit"
#define SortQuit 4

class Sorting
{
public:
	Sorting();
	~Sorting();
	void beginSort();

	//Heap
	void heapSort();
	void heapify(int length, int currentIndex);

	//merge
	void runMerge(int start, int end);
	void mergeSort(int start, int end);
	void merge(int start, int leftMiddle, int rightMiddle, int end);

	//Quick Sort
	void runQuickSort(int start, int end);
	void quickSort(int start, int end);
	int partition(int start, int end);
	int randomPartition(int start, int end);


	void verifySort();
	void returnVectorValuesToOriginal();
private:
	yhk helperTool;
	std::vector<int> values;
	std::vector<int> originalValues;
	int sortMethod;
	int length;
};