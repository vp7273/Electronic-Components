/*
 * Capacitor.cpp
 *
 *  Created on: Mar 16, 2018
 *      Author: Varika
 */





//Class implementation file for Capacitor class

#include <iostream>
#include "Capacitor.h"

using namespace std;



//Capacitor::Capacitor(double &capacitor_value) //constructor with one parameter defined INLINE


double Capacitor::GetValue()
{
	// Getting value of component
	cout << "Please enter a value for the component" << endl;

	char capacitorValue [100];// char array to allow input validation by character
		cin >> capacitorValue;

		long long unsigned int length = strlen(capacitorValue);//strlen returns long long unsigned int

		bool digit;
		int decimal =0;

		for (unsigned int count =0; count <length; count++)//goes through input character by character
		{
			digit = false;

			if (length == 1 && capacitorValue[0] == '.') //only decimal is entered
							{
								digit = false;
								break;
							}

			if (isdigit(capacitorValue[count]))
			{
				digit = true;
			}

			else if ( capacitorValue[count]== '.')
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
				cin >> capacitorValue;
				decimal = 0; //reset decimal count
				length = strlen(capacitorValue); //repeat character by character check
				for (unsigned int count =0; count <length; count++) //goes through input character by character
					{

						if (length == 1 && capacitorValue[0] == '.') //only decimal is entered
						{
							digit = false;
							break;
						}

						if (isdigit(capacitorValue[count]))
						{
							digit = true;
						}

						else if (capacitorValue[count] == '.')
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

		double capacitor_value = stod (capacitorValue);

		return capacitor_value;
}

const char* Capacitor::GetUnits()
{
	static char capacitorUnits[] = "Farad(s)"; //static variable so not destroyed when function ends and can be returned
	return capacitorUnits;
}

const char* Capacitor::GetDescription()
{
	    double value = capacitorValue;
		static char buffer[100]; //static to make local variable last after end of function
		sprintf(buffer, "%.6g", value);// converts double value to string
		strcat (buffer, " "); //adds space between value and units
		strcat(buffer, GetUnits()); //appends units to value
		return buffer;
}

  Capacitor::~Capacitor() //destructor
  {

  }
