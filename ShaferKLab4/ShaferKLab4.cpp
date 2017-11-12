#include "Standards.h"
#include "FileProcessing.h"

int main() {
	//VARIABLE DECLARATION

	//input and output files
	ifstream inputFile;
	ofstream outputFile;

	//END VARIABLE DECLARATION

	OutputCourseHeading(cout);

	//open input and output files
	inputFile = OpenInputFile("Listings.txt");
	outputFile = OpenOutputFile("results.txt");

	//read in the data from the input file
	InputHomes(inputFile);

	//close the input and output files
	inputFile.close();
	outputFile.close();

	return 0;
}