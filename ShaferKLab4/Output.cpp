//--------------------------------------------------------------------------------------------------
//Programmer's Name:  KC Shafer
//File Name: Output.cpp
//Associated File:  Output.h
//Functions: OutputFormattedListingdata
//--------------------------------------------------------------------------------------------------
#include "Standards.h"
#include "realtorStructType.h"

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

