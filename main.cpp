// main.cpp
// sortandsearch

/*
Two arrays are created from an external txt file.
One array is sorted using the bubble sort algorithm.
The other array is sorted using the selection sort algorithm.
The value 869 is located using the binary search and linear search algorithms.
The number of sort exchanges and search comparisons made for each algorithm is displayed.
*/

#include<iostream>
#include<fstream>

using namespace std;

class SortAndSearch
{
protected:
	ifstream inFile;	

public:
	SortAndSearch(char *inFileName);

	SortAndSearch() {};
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

// small main
int main()
{
	char inFileName[] = { "random.txt" };

	SortAndSearch sasObject( inFileName );
	
	sasObject.makeArray();
	
	sasObject.bubbleSort();
	sasObject.selectionSort();

	sasObject.linearSearch();
	sasObject.binarySearch();
	
	sasObject.display();

	return 0;
}

// open input file
SortAndSearch::SortAndSearch(char* inFileName)
{
	inFile.open(inFileName);
	if (!inFile)
	{
		cout << "The file " << inFileName << " cannot be opened." << endl;
		exit(1);
	}
}

// close input file
SortAndSearch::~SortAndSearch()
{
	inFile.close();
}

// fill the arrays
void SortAndSearch::makeArray()
{
	// populate arrayOne from txt file
	for (int i = 0; i < SIZE; i++) {
		inFile >> arrayOne[ i ];
	}
	// populate arrayTwo from arrayOne
	for (int i = 0; i < SIZE; i++) {
		arrayTwo[ i ] = arrayOne[ i ];
	}
}

// display info
void SortAndSearch::display()
{	
	cout << "\n ******************************************************" << endl;
	cout <<   " **            Sort and Search Benchmarks            **" << endl;
	cout <<   " ******************************************************" << endl<< endl;

	cout << "\t Bubble Sort exchanges: \t" << bubbleCount << endl;
	cout << "\t Selection Sort exchanges: \t" << selectionCount << endl << endl;
	cout << "\t Linear Search comparisons: \t" << linearCompares << endl;
	cout << "\t Binary Search comparisons: \t" << binaryCompares << endl;
	cout << endl << endl << endl << endl;
}

// bubble sort on arrayOne
void SortAndSearch::bubbleSort()
{
	int temp;
	bool swap;

	do {
		swap = false;
		for (int i = 0; i < ( SIZE - 1 ); i++) {
			if (arrayOne[ i ] > arrayOne[ i + 1 ]) {
				temp = arrayOne[ i];
				arrayOne[ i ] = arrayOne[ i + 1 ];
				arrayOne[ i + 1 ] = temp;
				
				swap = true;
				bubbleCount++;	// count exchanges made
			}
		}
	} 
	while ( swap );
}

// selection sort on arrayTwo
void SortAndSearch::selectionSort()
{
	int startScan;
	int	minIndex;
	int	minValue;

	for (startScan = 0; startScan < (SIZE - 1); startScan++) {
		minIndex = startScan;
		minValue = arrayTwo[ startScan ];

		for (int i = startScan + 1; i < SIZE; i++) {
			if (arrayTwo[ i ] < minValue) {
				minValue = arrayTwo[ i ];
				minIndex = i;

				selectionCount++;	// count exchanges made
			}
		}

		arrayTwo[ minIndex ] = arrayTwo[ startScan ];
		arrayTwo[ startScan ] = minValue;
	}
}

// linear search on arrayOne
void SortAndSearch::linearSearch()
{
	int i = 0;
	bool found = false;		// searchValue bool 

	while (i < SIZE && !found) {
		if (arrayOne[ i ] == searchValue) {
			found = true;
		}
		
		i++;
		linearCompares++;	// count comparisons made
	}
}

// binary search on arrayTwo
void SortAndSearch::binarySearch()
{
	int first = 0;
	int last = SIZE - 1;
	bool found = false;				// searchValue bool 

	while (first <= last && !found)
	{
		int middle = ( first + last ) / 2;
		binaryCompares++;			// count comparisons made

		if (searchValue == arrayTwo[ middle ])
			found = true;

		if (searchValue > arrayTwo[ middle ])
			first = middle + 1;		// upper half

		else
			last = middle - 1;		// lower half
	}
}
