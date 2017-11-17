//--------------------------------------------------------------------------------------------------
//Name:
//Program:  Lab 4
//Grade:
//General Comments:  
//   
//  
//  
//                   
//--------------------------------------------------------------------------------------------------
//Met Standard Programming Requirements
// Students should review this PDF file to assure these specs are met
//  which can be found in important Course Documents
//Project: 
// Input, output, header and CPP files attached to the project
// Standards - header & CPP file
// Struct - header & CPP file
// Class - header & CPP file
// main - driver for the program, includes IPO and grading block
// ALL FILES included in the folder
// Open from the Project Solution Window
//Comments:
//  
//  
//Points Lost ------------------------------------------------------------->  
//
//--------------------------------------------------------------------------------------------------
// Identifiers: (any points lost will be deducted in EACH function
//               where these style requirements are not met)
//  Variables - meaningful names to reflect what the data
//              represents, camel casing used, no abbreviations, 
//              blocked by type                                    
//  Constants - meaningful names, capitalization &
//              underscore used                                    
//--------------------------------------------------------------------------------------------------
//Function/Method Style :
// Function/Method(any points lost will be deducted in EACH method
//           where these style requirements are not met)
//  Names                  - meaningful names to reflect what the task of the function is                      
//  Prototypes             - No comments above, separated by one blank line                      
//  Definitions            - doc block with name, brief and accurate descriptions                  
//  Local Variables        - appropriately named, no abbreviations, blocked by type
//  Indentation            - all code indented correctly
//  Blocking               - all code blocked correctly, no extra blank lines
//  Internal Documentation - correctly done only for methods required in the instructions
//--------------------------------------------------------------------------------------------------
//Program Specifications
//
//Standard Functions
//  Divider
//  Course Heading
//  Centered Report Heading
//  File Message 
//Comments:
//  
//  
//  
//Points lost -----------------------------------------------------------------------------> 
//Output in General
//  All output to the output file
//  All output included, formatted as shown in the samples provided
//    in the lab specifications
//  One or two decimals displayed as shown in the samples
//  Data aligns in the columns as shown in the samples
//  Divider appropriately used to block the output
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//Required Definitions
//RealtorStructType 
//  members - name - string, array of houseClassType, tag field - int
//Comment:
//
//
//
//
//Points lost -----------------------------------------------------------------------------> 
//Functions
//InputHomes
// Agent's name input
// Primer and changer of location string used to input home data
// style input as a string with delimiter
// for loop used to input the counts for bedrooms, bathrooms, &  leisure rooms
// Input the type of garage, year built, price, taxes
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//Selection Sort House Data
//Sorted using the SAME selection sort as the previous labs
//Sorted ascending by listing number
//3 functions for this task - Sort, finding the index of the smallest & swapping houses
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//OutputAgentData
//Output to the opened output file, results.txt
//All output including the agent's name and each home's data with labels
//Blocked with a top divider above all output & blocked with a divider between each house data
//Total Listings output at the end of the report
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//OutputHomeWithANumberOfBedrooms
//Output a list of homes to the opened output file
// Output the number of bedrooms & the listing number & price of each home that meets the criteria
// Output the count of the number of matches
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//HomeSold
//Search the SORTED array of class struct members for the match of 
// a listing number passed in
// Searching should stop once a match is found or the search listing number
//  has exceeded the current listing number in the array of class struct 
// If match found, output all data for this home & 
//  remove the class struct member by moving the remaining members up
// If no match is found, output the listing number you were searching for & no match message
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//--------------------------------------------------------------------------------------------------
//houseClassType 
//  Created using UML provided
//  Private/Public members correctly defined
//  Code documented in the methods where necessary
//  Documentation above methods where required in the lab specifications
//Comment:
//
//
//
//
//Points lost -----------------------------------------------------------------------------> 
//definitions
// all member variables and member methods created as shown in the UML
// Constructor - sets string to null, double & int to 0
// Destructor - Outputs a message on the screen that the houseClassType
//  object was destroyed
// Get Methods (8)
//  location, style, room counts, capacity, year built, 
//  price, taxes, listing number
// Set Methods (10)
//  location, style, room counts, capacity, year built, 
//  price, taxes, listing number
//  county name
//   sets a string for the county name determined from the county code
//  school district name
//   sets a string for the school district name determined from the school district code
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
// Print Methods (9)
//  style, capacity, year built, 
//  price, taxes, listing number
//  PrintLocation
//   Parses the location string to output the:
//   state, county, city, school district & address
//    with labels aligned as shown in the sample
// PrintRoomCounts
//  Outputs the counts of the bedrooms, bathrooms, leisure rooms
//   with labels aligned as shown in the sample
// PrintHouse
//  Outputs all the house data aligned as shown in the sample
//  Listing number, style, state, county, city, school district, address,
//  counts of rooms, type of garage, year built, price & taxes
//  Outputs
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//ExtractLocationData
// Parse the location string to return(5): state, county, city, school district, address
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//--------------------------------------------------------------------------------------------------
//IPO
//Completed showing the flow of the program
//2 comment lines with instructions to complete the IPO deleted from grading/doc block
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//--------------------------------------------------------------------------------------------------
//Main
//  struct of realtorStructType defined
//  files opened, precision set
//  Data input in the struct from the input file
//  Unsorted struct data output to the file
//  House data sorted by listing number
//  Output Sorted struct data to the file
//  Output homes with 3 bedrooms
//  Output homes with 4 bedrooms
//  Output listing sold called 5 times with:
//    123, 369, 180, 987, 850
//  Output the Sorted struct data with homes sold removed to the file
//  files closed
//Comment:
//
//
//Points lost -----------------------------------------------------------------------------> 
//--------------------------------------------------------------------------------------------------
//Possible Lab Grade ---------------------------------------------------------------------->  200
//Total Points Lost  ---------------------------------------------------------------------->  
//Final Lab Grade ------------------------------------------------------------------------->   
//--------------------------------------------------------------------------------------------------
//
///COMPLETE THE IPO showing the flow in the main - this is a short IPO
///DELETE these two comment lines before submitting the lab
//-------------------Main Doc Block-----------------------------------------------------------------
//IPO:
// Open the input & output files
// Set the formatting to 2 decimals for the output file
// Input the agent's data from the input file
//
//
//
//
//
//
//
//
//
//
//
//--------------------------------------------------------------------------------------------------

#include "Standards.h"
#include "FileProcessing.h"
#include "Output.h"

int main() {
	//VARIABLE DECLARATION

	//input and output files
	ifstream inputFile;
	ofstream outputFile;

	//realtor struct type variable
	realtorStructType realtor;

	//END VARIABLE DECLARATION

	OutputCourseHeading(cout);

	//open input and output files
	inputFile = OpenInputFile("Listings.txt");
	outputFile = OpenOutputFile("results.txt");

	//read in the data from the input file
	realtor = InputHomes(inputFile);
	
	//output the unsorted realtor & listing data
	OutputFormattedListingData(outputFile, realtor, "Output of the data read in");

	//sort listings by listing number
	SortListings(realtor);

	//output sorted listings
	OutputFormattedListingData(outputFile, realtor, "Output of sorted listings");

	//output three bedroom listings
	OutputListingsByBedroom(outputFile, realtor, 3, "The following listings have 3 bedrooms");
	
	//output four bedroom listings
	OutputListingsByBedroom(outputFile, realtor, 4, "The following listings have 4 bedrooms");

	//close the input and output files
	inputFile.close();
	outputFile.close();

	return 0;
}