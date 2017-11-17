//--------------------------------------------------------------------------------------------------
//Programmer's Name:  KC Shafer
//File Name: Standards.cpp
//Associated File:  Standards.h
//Functions: OutputMsg, OutputDivider, OutputCourseHeading, OpenInputFile, OpenOutputFile`
//--------------------------------------------------------------------------------------------------
#include "Standards.h"

//-------------------------------------------------------------------
// OutputMsg - output msg to passed stream
//-------------------------------------------------------------------
void OutputMsg(ostream& out, string msg) {
	out << msg << endl;
}

//-------------------------------------------------------------------
// OutputCenteredMsg - output centered message msg to passed file 
//-------------------------------------------------------------------
void OutputCenteredMsg(ofstream& outputFile, string msg) {
	OutputCenteredMsg(outputFile, msg, DIVIDER_WIDTH);
}

//-------------------------------------------------------------------
// OutputCenteredMsg - output centered message msg to passed file 
//-------------------------------------------------------------------
void OutputCenteredMsg(ofstream& outputFile, string msg, int length) {
	outputFile << setfill(' ') <<  setw((length + msg.size()) / 2) << msg << endl;
}

//-------------------------------------------------------------------
// Output Divider - output the standard dashed divider line to the 
// passed by ref output stream
//-------------------------------------------------------------------
void OutputDivider(ostream& out, char dividerChar) {
	out << setfill(dividerChar) << setw(HEADING_WIDTH) << ' ' << setfill(' ') << endl;
}

//-------------------------------------------------------------------
// Output Divider - output the standard dashed divider line to the 
// passed by ref output stream
//-------------------------------------------------------------------
void OutputDivider(ofstream& outputFile, char dividerChar) {
	outputFile << setfill(dividerChar) << setw(DIVIDER_WIDTH) << ' ' << setfill(' ') << endl;
}

//-------------------------------------------------------------------
// Output Divider - output divider using passed length and character
//-------------------------------------------------------------------
void OutputDivider(ofstream& outputFile, char dividerChar, int dividerLength) {
	outputFile << setfill(dividerChar) << setw(dividerLength) << ' ' << setfill(' ') << endl;
}

//-------------------------------------------------------------------
// OutputHalfDivider - output half length divider to output file
//-------------------------------------------------------------------
void OutputHalfDivider(ofstream& outputFile, char dividerChar) {
	OutputHalfDivider(outputFile, dividerChar, DIVIDER_WIDTH);
}

//-------------------------------------------------------------------
// OutputHalfDivider - output half length divider to output file
//-------------------------------------------------------------------
void OutputHalfDivider(ofstream& outputFile, char dividerChar, int fullLength) {
	OutputDivider(outputFile, dividerChar, (fullLength / 2));
}

//-------------------------------------------------------------------
//OutputCourseHeading - output constant course information to header
// of passed by ref file
//-------------------------------------------------------------------
void OutputCourseHeading(ostream& out) {
	OutputDivider(out, '-');

	out << setfill(' ') << setw((COLLEGE.length() + HEADING_WIDTH) / 2) << COLLEGE << endl;
	out << setfill(' ') << setw((NAME.length() + HEADING_WIDTH) / 2) << NAME << endl;
	out << setfill(' ') << setw((ASSIGNMENT.length() + HEADING_WIDTH) / 2) << ASSIGNMENT << endl;

	OutputDivider(out, '-');
}

//-------------------------------------------------------------------
// OpenInputFileName - takes in a fileName and opens it as a
// ifstream inputfile and returns it 
//-------------------------------------------------------------------
ifstream OpenInputFile(string fileName) {
	//initialize input file
	ifstream inputFile;

	//open the input file with the passed file name
	inputFile.open(fileName);

	OutputMsg(cout, fileName + "is an input file, found in the project folder");

	return inputFile;
}

//-------------------------------------------------------------------
// OpenOutputFile - takes in a string file name and opens an ofstream
// with the name and returns it 
//-------------------------------------------------------------------
ofstream OpenOutputFile(string fileName) {
	//initialize output file
	ofstream outputFile;

	//open the output file with the passed file name
	outputFile.open(fileName);

	//set the output file fill to spaces
	outputFile << setfill(' ');

	//set output file precision
	outputFile << fixed << setprecision(1);

	OutputMsg(cout, fileName + "is an output file, found in the project folder");

	return outputFile;
}
