#ifndef Output__h
#define Output__h

//--------------------------------------------------------------------------------------------------
//Programmer:       KC Shafer
//File Name:		Output.h
//Associated file:  Output.cpp
//Header contains
// - Functions related to outputting data to output file(s)
// - OutputFormattedListingData
//--------------------------------------------------------------------------------------------------

#include "Standards.h"
#include "houseClassType.h";
#include "realtorStructType.h"

void OutputFormattedListingData(ofstream& outputFile, realtorStructType realtor, string msg);

#endif // !Output__h
