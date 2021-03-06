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
void SwapInstances(houseClassType& first, houseClassType& second);
int IndexOfSmallest(houseClassType listings[30], int arraySize, int index);
void SortListings(realtorStructType& realtor);
void OutputListingsByBedroom(ofstream& outputFile, realtorStructType realtor, int numBedrooms, string msg);
void OutputListingSubset(ofstream& outputFile, houseClassType listings[30], int listingsCount);
void HomeSold(ofstream& outputFile, realtorStructType& realtor, int listingNumber);
int FindByListingNumber(int listingNumber, houseClassType listings[30], int listingCount);
void AdjustListingArray(houseClassType listings[30], int listingCount, int removeIndex);

#endif // !Output__h
