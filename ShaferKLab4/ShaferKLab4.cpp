#include "Standards.h"
#include "FileProcessing.h"

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
	
	realtor.listings[0].PrintHouse(outputFile);

	//close the input and output files
	inputFile.close();
	outputFile.close();

	return 0;
}