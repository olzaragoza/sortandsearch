/* sortandsearch.cpp */

#include "sortandsearch.h"
#include <iostream>

// open input file
SortAndSearch::SortAndSearch(char* inFileName)
{
	inFile.open(inFileName);
	if (!inFile)
	{
		std::cout << "The file " << inFileName << " cannot be opened." << std::endl;
		exit(1);
	}
}

// close input file
SortAndSearch::~SortAndSearch()
{
	inFile.close();
}