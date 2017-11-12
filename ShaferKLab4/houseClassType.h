#ifndef houseClassType__h
#define houseClassType__h
//--------------------------------------------------------------------------------------------------
//Programmer:       KC Shafer
//File Name:		houseClassType.h
//Associated file:  houseClassType.cpp
//Header contains
// - houseClassType definition
// - 
//--------------------------------------------------------------------------------------------------

#include "Standards.h"

class houseClassType {
	//private properties
	private:
		//house class type variables
		string location;
		string style;
		string countyName;
		string schoolDistrictName;
		double roomCounts[3];
		int capacityOfGarage;
		int yearBuilt;
		double price;
		double taxes;
		int listingNumber;

	//public functions
	public:
		//constructor definition
		houseClassType();

		//inline getters
		string GetLocation() { return location; }
		string GetStyle() { return style; }
		string GetCountyName() { return countyName; }
		string GetSchoolDistrictName() { return schoolDistrictName; }
		int GetCapacityOfGarage() { return capacityOfGarage; }
		int GetYearBuilt(){ return yearBuilt; }
		double GetPrice() { return price; }
		double GetTaxes() { return taxes; }
		int GetListingNumber() { return listingNumber; }

		//GetListingNumber defintion
		void GetRoomCounts(double roomCounts[]);

		//basic setters definition
		void SetLocation(string location);
		void SetStyle(string style);
		void SetRoomCounts(double roomCounts[]);
		void SetCapacityOfGarage(int capacityOfGarage);
		void SetYearBuilt(int yearBuilt);
		void SetPrice(double price);
		void SetTaxes(double taxes);
		void SetListingNumber(int listingNumber);

		//complex setters defintion
		void SetCountyName();
		void SetCountyName(string countyCode);
		void SetSchoolDistrictName();

		//print methods definition (to file)
		void PrintStyle(ofstream& outputFile);
		void PrintCapacityOfGarage(ofstream& outputFile);
		void PrintYearBuilt(ofstream& outputFile);
		void PrintPrice(ofstream& outputFile);
		void PrintTaxes(ofstream& outputFile);
		void PrintListingNumber(ofstream& outputFile);
		
		//complex print defintion
		void PrintLocationData(ofstream& outputFile);
		void PrintRoomCounts(ofstream& outputFile);
		void PrintHouse(ofstream& outputFile);

		//extract abbreviated location data as string definition
		void ExtractLocationData(string& state, string& countyCode, string& city, string& districtCode, string& address);
};

#endif // !houseClassType__h