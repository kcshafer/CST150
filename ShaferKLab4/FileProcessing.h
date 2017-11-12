#ifndef FileProcessing__h
#define FileProcessing__h
//--------------------------------------------------------------------------------------------------
//Programmer:       KC Shafer
//File Name:		FileProcessing.h
//Associated file:  FilePRocessing.cpp
//Header contains
// - Functions related to processing input and output files specifically for this program
// - InputHomes
//--------------------------------------------------------------------------------------------------

#include "Standards.h"
#include "houseClassType.h";
#include "realtorStructType.h"

realtorStructType InputHomes(ifstream& inputFile);
houseClassType CreateListing(ifstream& inputFile);

#endif // !FileProcessing__h