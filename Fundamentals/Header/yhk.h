#pragma once
#ifndef yhk_h

// Definitions
#define yhk_h
#define MAX_SIZE 1000
#define MAIN_MESSAGE "MAIN MENU - 1: Sorting, 2: Linked Lists, 3: Binary Search Trees, 4: Algorithms "
#define NEWLINE std::cout << std::endl;
#define QUIT 0
#define INVALID_INPUT 99
#define START_COMMANDS 200149907
#define LIST_MESSAGE "Insert new Linked List Node value."

// Input/Output
#include <iostream>

//Data Structures
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <stack>

//Strings
#include <sstream>
#include <string>
#include <cstring>
#include <locale>

//Memory
#include <cstdlib>
#include <stdlib.h>

#endif

class yhk
{
public:
	void keepCommandPromptOpen();
	int getIntInput(std::string message, bool newLine);
	void outputVector(std::vector<int> arr, bool newLine, bool outputStatement);
	void swap(std::vector<int> &vec, int firstIndex, int secondIndex);
	bool equalVectors(std::vector<int> vec1, std::vector<int> vec2);
private:

};