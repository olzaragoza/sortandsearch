/* sortandsearch.h */

#pragma once

class SortAndSearch
{
protected:
	ifstream inFile;

public:
	SortAndSearch(char *inFileName);

	SortAndSearch();
	~SortAndSearch();

	static const int SIZE = 200;	// size of array
	int searchValue = 869;			// search array for this value

	// arrays
	int arrayOne[ SIZE ];
	int arrayTwo[ SIZE ];

	int bubbleCount = 0;		// bubbleSort exchange count
	int selectionCount = 0;		// selectionSort exchange count
	int linearCompares = 0;		// linearSearch comparison count
	int binaryCompares = 0;		// binarySearch comparison count

	void makeArray();
	void display();
	
	// sorts
	void bubbleSort();
	void selectionSort();
	// searches
	void linearSearch();
	void binarySearch();
};