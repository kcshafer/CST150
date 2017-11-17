//--------------------------------------------------------------------------------------------------
//Programmer's Name:  KC Shafer
//File Name: Output.cpp
//Associated File:  Output.h
//Functions: OutputFormattedListingdata
//--------------------------------------------------------------------------------------------------
#include "Standards.h"
#include "realtorStructType.h"
#include "Output.h"

//-------------------------------------------------------------------
// OutputFormattedListingData - output the listing data for a realtor
// formatted to the output file
//-------------------------------------------------------------------
void OutputFormattedListingData(ofstream& outputFile, realtorStructType realtor, string msg) {
	//loop control variable
	int index;
	
	//output report title
	OutputDivider(outputFile, '-');
	OutputCenteredMsg(outputFile, msg);
	OutputDivider(outputFile, '-');

	//output realtor name
	outputFile << setfill(' ') << "Agent's Name" << setw(20) << realtor.agentName << endl;
	outputFile << "This agent's listings are:" << endl;
	
	OutputHalfDivider(outputFile, '-');

	//loop through realtor's listings
	for(index = 0; index < realtor.listingCount - 1; index++) {
		realtor.listings[index].PrintHouse(outputFile);
	}
	
	outputFile << setfill(' ') << "Total Listings" << setw(20) << realtor.listingCount << endl;
}

//-------------------------------------------------------------------
// SwapInstanes - swap two passed houseClassType instances, used for
// sorting
//-------------------------------------------------------------------
void SwapInstances(houseClassType& first, houseClassType& second) {
	houseClassType temp;

	temp = first;
	first = second;
	second = temp;
}


//-------------------------------------------------------------------
// IndexOfSmallest - based on passed range, find the smallest value in
// that range in the array and return index to caller
//-------------------------------------------------------------------
int IndexOfSmallest(houseClassType listings[30], int arraySize, int index) {
	int smallestIndex;
	int minIndex;

	smallestIndex = index;

	for(minIndex = index + 1; minIndex < arraySize; minIndex++) {
		if(listings[minIndex].GetListingNumber() < listings[smallestIndex].GetListingNumber()) {
			smallestIndex = minIndex;
		}
	}

	return smallestIndex;
}

//-------------------------------------------------------------------
// SortStateData - selection sort implementation with variable
// sort target, based on passed enum value
//-------------------------------------------------------------------
void SortListings(realtorStructType& realtor) {
	int smallestIndex;
	int index;

	for(index = 0; index < realtor.listingCount - 1; index++) {
		smallestIndex = IndexOfSmallest(realtor.listings, realtor.listingCount, index);

		SwapInstances(realtor.listings[index], realtor.listings[smallestIndex]);
	}
}

//-------------------------------------------------------------------
// OutputListingsByBedroom - get (x) bedroom listings, output title
// and pass to subset output function
//-------------------------------------------------------------------
void OutputListingsByBedroom(ofstream& outputFile, realtorStructType realtor, int numBedrooms, string msg) {
	//array to hold subset generated
	houseClassType threeBedroomListings[30];
	
	//three bedroom listings count
	int threeBedroomCount;

	//loop control variable
	int index;

	//double array to hold room counts
	double roomCounts[3];

	//init three bedroom count to 0
	threeBedroomCount = 0;

	for(index = 0; index < realtor.listingCount; index++) {
		//get room counts
		realtor.listings[index].GetRoomCounts(roomCounts);

		//check if bedrooms on listing is equal to 3
		cout << "ROOM COUNT " << roomCounts[0] << endl;
		if(roomCounts[0] == numBedrooms) {
			threeBedroomListings[threeBedroomCount] = realtor.listings[index];
			threeBedroomCount++;
		}
	}

	//output report title
	OutputDivider(outputFile, '*', 75);
	OutputCenteredMsg(outputFile, msg, 75);
	OutputDivider(outputFile, '*', 75);

	OutputListingSubset(outputFile, threeBedroomListings, threeBedroomCount);

	OutputDivider(outputFile, '~', 75);

	outputFile << setfill(' ') << "Count Of Matches: " << setw(10) << (threeBedroomCount == 0 ? "No matches found " : to_string(threeBedroomCount)) << endl;

	OutputDivider(outputFile, '~', 75);
}

//-------------------------------------------------------------------
// OutputListingSubset - output passed array subset of listings
//-------------------------------------------------------------------
void  OutputListingSubset(ofstream& outputFile, houseClassType listings[30], int listingsCount) {
	//loop control variable
	int index;

	for(index = 0; index < listingsCount; index++) {
		outputFile << setfill(' ') << setw(10) << listings[index].GetListingNumber();
		outputFile << setw(10) << listings[index].GetPrice();
		outputFile << endl;
	}
}