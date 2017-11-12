#ifndef realtorStructType__h
#define realtorStructType__h
//--------------------------------------------------------------------------------------------------
//Programmer:       KC Shafer
//File Name:		realtorStructType.h
//Associated file:  realtorStructType.cpp
//Header contains
// - realtorStructType definition
// - 
//--------------------------------------------------------------------------------------------------

#include "Standards.h"
#include "houseClassType.h"

struct realtorStructType {
	string agentName;
	houseClassType listings[30];
	integer listingCount;
};

#endif // !realtorStructType__h