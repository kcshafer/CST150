//--------------------------------------------------------------------------------------------------
//Programmer's Name:  KC Shafer
//File Name: Standards.cpp
//Associated File:  houseClassType.h
//Purpose: implement the member functions of houseClassType
//--------------------------------------------------------------------------------------------------

#include "houseClassType.h"

//--------------------------------------------------------------------------------------------------
// no argument constructor - defaults strings to null and numerics to 0
//--------------------------------------------------------------------------------------------------
houseClassType::houseClassType() {
	location         = "";
	style            = "";
	capacityOfGarage = 0;
	yearBuilt        = 0;
	price            = 0;
	taxes            = 0;
	listingNumber    = 0;
}

// GETTERS

//--------------------------------------------------------------------------------------------------
// GetRoomCounts - set passed by reference array with values in room counts
//--------------------------------------------------------------------------------------------------
void houseClassType::GetRoomCounts(double roomCounts[]) {
	roomCounts[0] = roomCounts[0];
	roomCounts[1] = roomCounts[1];
	roomCounts[2] = roomCounts[2];
}

// END GETTERS

//SETTERS

//--------------------------------------------------------------------------------------------------
// SetLocation - set location property with passed value
//--------------------------------------------------------------------------------------------------
void houseClassType::SetLocation(string location) {
	this->location = location;
}

//--------------------------------------------------------------------------------------------------
// SetStyle - set style property with passed value
//--------------------------------------------------------------------------------------------------
void houseClassType::SetStyle(string style) {
	this->style = style;
}

//--------------------------------------------------------------------------------------------------
// SetRoomCounts - set room counts property with passed value
//--------------------------------------------------------------------------------------------------
void houseClassType::SetRoomCounts(double roomCounts[]) {
	this->roomCounts[0] = roomCounts[0];
	this->roomCounts[1] = roomCounts[1];
	this->roomCounts[2] = roomCounts[2];
}

//--------------------------------------------------------------------------------------------------
// SetGarageCapacity - set garage capacity property with passed value
//--------------------------------------------------------------------------------------------------
void houseClassType::SetCapacityOfGarage(int capacityOfGarage) {
	this->capacityOfGarage = capacityOfGarage;
}

//--------------------------------------------------------------------------------------------------
// SetYearBuilt - set year built property with passed value
//--------------------------------------------------------------------------------------------------
void houseClassType::SetYearBuilt(int yearBuilt) {
	this->yearBuilt = yearBuilt;
}

//--------------------------------------------------------------------------------------------------
// SetPrice - set price property with passed value
//--------------------------------------------------------------------------------------------------
void houseClassType::SetPrice(double price) {
	this->price = price;
}

//--------------------------------------------------------------------------------------------------
// SetStyle - set style property with passed value
//--------------------------------------------------------------------------------------------------
void houseClassType::SetTaxes(double taxes) {
	this->taxes = taxes;
}

//--------------------------------------------------------------------------------------------------
// SetListingNumber - set listing number property with passed value
//--------------------------------------------------------------------------------------------------
void houseClassType::SetListingNumber(int listingNumber) {
	this->listingNumber = listingNumber;
}

//--------------------------------------------------------------------------------------------------
// SetCountyName - set the county name based on the two character county code retrieved from location
// string, overload to retrieve that county code then pass to setter with county code
//--------------------------------------------------------------------------------------------------
 void houseClassType::SetCountyName() {
	//variable to store county code
	string countyCode;

	//get county code out of location string using position
	countyCode = this->location.substr(2,2);

	this->SetCountyName(countyCode);
}

 void houseClassType::SetCountyName(string countyCode) {
	//block to set full county name
	if(countyCode == "BC") {
		this->countyName = "Broome";
	}
	else if(countyCode == "TC") {
		this->countyName = "Tioga";
	}
	else if(countyCode == "BR") {
		this->countyName = "Bradford";
	}
	else {
		this->countyName = "Unknown";
	}
 }

void houseClassType::SetSchoolDistrictName() {
	//variable to store school district code
	string schoolDistrictCode;

	//get school district code from location string using position
	schoolDistrictCode = this->location.substr(36,2);

	if(schoolDistrictCode == "UE") {
		this->schoolDistrictName = "Union Endicott";
	}
	else if(schoolDistrictCode == "JC") {
		this->schoolDistrictName = "Johnson City";
	}
	else if(schoolDistrictCode == "OA") {
		this->schoolDistrictName = "Owego Appalachin";
	}
	else if(schoolDistrictCode == "TR") {
		this->schoolDistrictName = "Troy";
	}
	else if(schoolDistrictCode == "SA") {
		this->schoolDistrictName = "Sayre";
	}
	else if(schoolDistrictCode == "AT") {
		this->schoolDistrictName = "Athens";
	}
	else if(schoolDistrictCode == "BG") {
		this->schoolDistrictName = "Binghamton";
	}
	else if(schoolDistrictCode == "VS") {
		this->schoolDistrictName = "Vestal";
	}
	else if(schoolDistrictCode == "ME") {
		this->schoolDistrictName = "Maine Endwell";
	}
	else if(schoolDistrictCode == "GR") {
		this->schoolDistrictName = "Greene";
	}
	else {
		this->schoolDistrictName = "Unknown";
	}
}
// END SETTERS

// PRINT METHODS 

//--------------------------------------------------------------------------------------------------
// PrintStyle - print the style property to file
//--------------------------------------------------------------------------------------------------
void houseClassType::PrintStyle(ofstream& outputFile) {
	outputFile << this->style << endl;
}

//--------------------------------------------------------------------------------------------------
// PrintCapacityOfGarage - print the capacity of garage property to file
//--------------------------------------------------------------------------------------------------
void houseClassType::PrintCapacityOfGarage(ofstream& outputFile) {
	outputFile << this->capacityOfGarage << endl;
}

//--------------------------------------------------------------------------------------------------
// PrintYearBuilt - print the capacity of garage property to file
//--------------------------------------------------------------------------------------------------
void houseClassType::PrintYearBuilt(ofstream& outputFile) {

}

//--------------------------------------------------------------------------------------------------
// PrintLocationDate - print formatted location data broken down into individual components
//--------------------------------------------------------------------------------------------------
void houseClassType::PrintLocationData(ofstream& outputFile) {
	//variables to store state, countyCode, city, district code and address
	string state;
	string countyCode;
	string city;
	string districtCode;
	string address;

	//variables to store translated county and school district
	string county;
	string schoolDistrict;

	//retrieve parsed location data
	this->ExtractLocationData(state, countyCode, city, districtCode, address);

	//retrieve the full county name and school district name
	county = this->GetCountyName();
	schoolDistrict = this->GetSchoolDistrictName();

	//set the outputfile fill
	outputFile << setfill(' ');

	//output formatted values to file
	outputFile << setw(19) << "State:" << state << endl;
	outputFile << setw(18) << "County:" << county << endl;
	outputFile << setw(20) << "City:"  << city << endl;
	outputFile << setw(5) << "School District:" << schoolDistrict << endl;
	outputFile << setw(18) << "Address: " << address << endl;
}

// END PRINT METHODS

//--------------------------------------------------------------------------------------------------
// ExtractLocationData - find all the location data for a house from the location string, setting on
// the passed by reference variables
//--------------------------------------------------------------------------------------------------
void houseClassType::ExtractLocationData(string& state, string& countyCode, string& city, string& districtCode, string& address) {
	state = this->location.substr(0, 2);
	countyCode = this->location.substr(2, 2);
	city = this->location.substr(4, this->location.find(' '));
	districtCode = this->location.substr(36, 2);
	address = this->location.substr(39);
}