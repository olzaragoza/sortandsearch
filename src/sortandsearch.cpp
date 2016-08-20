/* sortandsearch.cpp */

#include "sortandsearch.h"

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