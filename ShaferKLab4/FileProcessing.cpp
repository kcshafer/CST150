//--------------------------------------------------------------------------------------------------
//Programmer's Name:  KC Shafer
//File Name: FileProcessing.cpp
//Associated File:  FileProcessing.h
//Purpose: implement file processing functions
//--------------------------------------------------------------------------------------------------

#include "FileProcessing.h"

//-------------------------------------------------------------------
// InputHomes - read in the input file
//-------------------------------------------------------------------
void InputHomes(ifstream& inputFile) {
	//string to hold the realtor name
	string realtorName;

	//read in the realtor name, the 1st line of the file
	getline(inputFile, realtorName);

	//variables to hold house lising properties
	string location;
	
	//variable to hold houseClassType 
	houseClassType listing;

	getline(inputFile, location);

	listing = houseClassType();

	listing.SetLocation(location);

}