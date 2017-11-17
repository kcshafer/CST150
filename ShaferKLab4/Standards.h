#ifndef Standards_h
#define Standards_h
//--------------------------------------------------------------------------------------------------
//Programmer:       KC Shafer
//File Name:        Standards.h
//Associated file:  None
//Header contains
// - Preprocessor Directives
// - Constant Declarations
//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void OutputMsg(ostream& out, string msg);
void OutputCenteredMsg(ofstream& outputFile, string msg);
void OutputCenteredMsg(ofstream& outputFile, string msg, int length);
void OutputDivider(ostream& out, char dividerChar);
void OutputDivider(ofstream& outputFile, char dividerChar);
void OutputDivider(ofstream& outputFile, char dividerChar, int length);
void OutputHalfDivider(ofstream& outputFile, char dividerChar);
void OutputHalfDivider(ofstream& outputFile, char dividerChar, int fullLength);
void OutputCourseHeading(ostream& out);
ifstream OpenInputFile(string fileName);
ofstream OpenOutputFile(string fileName);

const int HEADING_WIDTH = 75;
const int DIVIDER_WIDTH = 110;

//Course heading constants
const string COLLEGE = "SUNY Broome Community College";
const string NAME = "KC Shafer";
const string ASSIGNMENT = "CST 150 - Lab 2";

#endif // !Standards_h
