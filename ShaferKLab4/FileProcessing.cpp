//--------------------------------------------------------------------------------------------------
//Programmer's Name:  KC Shafer
//File Name: FileProcessing.cpp
//Associated File:  FileProcessing.h
//Purpose: implement file processing functions
//--------------------------------------------------------------------------------------------------

#include "FileProcessing.h"
#include "realtorStructType.h"

//-------------------------------------------------------------------
// InputHomes - read in the input file
//-------------------------------------------------------------------
realtorStructType InputHomes(ifstream& inputFile) {
	//realtor struct type
	realtorStructType realtor;

	//initialize realtor number of listings to 0
	realtor.listingCount = 0;

	//read in the realtor name, the 1st line of the file
	getline(inputFile, realtor.agentName);
	
	//input file processing loop
	while(!inputFile.eof() && realtor.listingCount < 30) {
		cout << "in loop" << endl;
		realtor.listings[realtor.listingCount] = CreateListing(inputFile);
		realtor.listingCount++;
	}

	return realtor;
}

houseClassType CreateListing(ifstream& inputFile) {
	//houseClassType class variable
	houseClassType listing;

	//temporary variable to hold input file data
	string tempStr;

	//array of doubles to store room counts - instantiated with 0's
	double tempRoomCounts[3] = {0};

	//instantiate new houseClassType
	listing = houseClassType();

	//retrieve location line from file and set on listing
	getline(inputFile, tempStr);
	listing.SetLocation(tempStr);

	cout << "LOCATION TEMP -> " << tempStr << endl;
	cout << "LOCATION CLASS -> " << listing.GetLocation() << endl;

	//retrieve style from file and set on listing
	getline(inputFile, tempStr, '*');
	listing.SetStyle(tempStr);

	//discard whitespace
	ws(inputFile);

	//retrieve number of bedrooms and set in array
	getline(inputFile, tempStr, ' ');
	tempRoomCounts[0] = stod(tempStr);

	//retrieve number of bathrooms and set in array
	getline(inputFile, tempStr, ' ');
	tempRoomCounts[1] = stod(tempStr);

	//retrieve number of leisure rooms and set in array
	getline(inputFile, tempStr, ' ');
	tempRoomCounts[2] = stod(tempStr);
	
	listing.SetRoomCounts(tempRoomCounts);

	//retrieve garage size and set on listing
	getline(inputFile, tempStr, ' ');
	listing.SetCapacityOfGarage(stod(tempStr));

	//retrieve year build and set on listing
	getline(inputFile, tempStr, ' ');
	listing.SetYearBuilt(stoi(tempStr));

	//retrieve price and set on listing
	getline(inputFile, tempStr, ' ');
	cout << "PRICE -> " << tempStr << endl;
	listing.SetPrice(stod(tempStr));

	//retrieve taxes and set on listing
	getline(inputFile, tempStr, ' ');
	listing.SetTaxes(stod(tempStr));

	//retrieve listing number and set on listing
	getline(inputFile, tempStr, '\n');
	listing.SetListingNumber(stoi(tempStr));
			
	return listing;
}