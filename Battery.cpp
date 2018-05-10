/*
 * Battery.cpp
 *
 *  Created on: Mar 16, 2018
 *      Author: Varika
 */


//Class implementation file for Battery class

#include <iostream>
#include "Battery.h"


using namespace std;


//Battery::Battery(double &battery_value)//constructor with one parameter defined INLINE


double Battery::GetValue()
{
	// Getting value of component
	cout << "Please enter a value for the component" << endl;

	   char batteryValue [100];// char array to allow input validation by character
		cin >> batteryValue;

		long long unsigned int length = strlen(batteryValue);//strlen returns long long unsigned int


		bool digit;
		int decimal = 0 ;

		for (unsigned int count =0; count <length; count++)//goes through input character by character
		{
			digit = false;

			if (length == 1 && batteryValue[0] == '.') //only decimal is entered
					{
						digit = false;
						break;
					}

			if (isdigit(batteryValue[count]))
			{
				digit = true;
			}

			else if (batteryValue[count]== '.')
		   {
			 digit = true;
			 decimal++;
		  }

			if (digit == false || decimal >1) //if a nondigit or decimal is found, for loop breaks and goes to while loop
				break;
		}

		while (digit == false || decimal >1 ) //input validation
			{
				cout << "Entry not accepted. Please enter ONLY a positive, floating" << endl;
				cout << "point value" << endl <<endl;
				cout << "Please enter a value for the component" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> batteryValue;
				decimal = 0; //reset decimal count
				length = strlen(batteryValue); //repeat character by character check
				for (unsigned int count =0; count <length; count++) //goes through input character by character
					{

						if (length == 1 && batteryValue[0] == '.') //only decimal is entered
						{
							digit = false;
							break;
						}

						if (isdigit(batteryValue[count]))
						{
							digit = true;
						}

						else if (batteryValue[count] == '.')
						{
							digit = true;
							decimal++;
						}
						else
							{

							digit = false; //if a nondigit or decimal is found, for loop breaks and goes to while loop
							break;
							}
					}


			}

		//after value accepted; conversion from string to double before returning

		double battery_value = stod (batteryValue);

		return battery_value;
}



const char* Battery::GetUnits()
{
	static char batteryUnits[] = "Volt(s)"; //static variable so not destroyed when function ends and can be returned
	return batteryUnits;
}


const char* Battery::GetDescription()
{
	double value = batteryValue;
	static char buffer[100]; //static to make local variable last after end of function
	sprintf(buffer, "%.6g", value);// converts double value to string
	strcat (buffer, " "); //adds space between value and units
	strcat(buffer, GetUnits()); //appends units to value
	return buffer;
}

   Battery::~Battery()//destructor
   {

   }




