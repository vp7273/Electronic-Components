/*
 * Resistor.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: Varika
 */



//Class implementation file for Resistor class

#include "Resistor.h"


using namespace std;


//Resistor::Resistor(double &resistor_value) //constructor with one parameter
//defined INLINE


double Resistor::GetValue()
{
	// Getting value of component
	cout << "Please enter a value for the component" << endl;

	char resistorValue [100]; // char array to allow input validation by character
	cin >> resistorValue;

	long long unsigned int length = strlen(resistorValue); //strlen returns long long unsigned int

	bool digit;
	int decimal = 0;

	for (unsigned int count =0; count <length; count++) //goes through input character by character
	{
		digit = false;
		if (length == 1 && resistorValue[0] == '.') //only decimal is entered
		{
			digit = false;
			       break;
		}
		if (isdigit(resistorValue[count]))
		{
			digit = true;
		}

		else if (resistorValue[count] == '.')
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
		cin >> resistorValue;
		decimal = 0; //reset decimal count
		length = strlen(resistorValue); //repeat character by character check
		for (unsigned int count =0; count <length; count++) //goes through input character by character
			{

				if (length == 1 && resistorValue[0] == '.') //only decimal is entered
				{
					digit = false;
					break;
				}

				if (isdigit(resistorValue[count]))
				{
					digit = true;
				}

				else if (resistorValue[count] == '.')
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

	double resistor_value = stod (resistorValue);

	return resistor_value;
}

const char* Resistor::GetUnits()
{
	static char resistorUnits[] = "Ohm(s)";
	return resistorUnits;
}

const char* Resistor::GetDescription()
{
	double value = resistorValue;
	static char buffer[100]; //static to make local variable last after end of function
	sprintf(buffer, "%.6g", value);// converts double value to string
	strcat (buffer, " "); //adds space between value and units
	strcat(buffer, GetUnits()); //appends units to value
	return buffer;
}

 Resistor::~Resistor() //destructor
{

}

