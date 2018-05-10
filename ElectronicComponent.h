/*
 * ElectronicComponent.h
 *
 *  Created on: Mar 15, 2018
 *      Author: Varika
 */

#ifndef ELECTRONICCOMPONENT_H_
#define ELECTRONICCOMPONENT_H_








#include <iostream> //overloading ostream operator
#include <cstdio> //sprintf used in derived classes
#include <cctype>//input validation; isdigit function used to check component values
#include <cstring> //derived classes use strcat for getdescription function; including once in base class for simplicity
//cstring also needed for overloading operator below for strcmp function
//strlen function also used in derived classes


using namespace std;

class Electronic_Component //BASE CLASS
{
public:

	virtual double GetValue() = 0;

	virtual const char* GetUnits()  = 0;

	virtual const char* GetDescription()  = 0;

	virtual ~Electronic_Component() {} // virtual destructor

//overloading of operator for first iteration (pointers)
	friend ostream& operator << (ostream &os, Electronic_Component *obj) //pointer used because main function uses pointers to objects

	{
		os << obj->GetDescription();
		return os;
	}

/* overloading operator for second iteration (dereferenced pointer according to code fragment given:
	cout << "Component " << count << " "
	 << *components[index] << endl;
	*/
	friend ostream& operator << (ostream &os, Electronic_Component &obj)
{

		//if conditions to check type of component by comparing strings of Units type


		char ohms []= "Ohm(s)";
		char farads [] = "Farad(s)";
		char volts [] = "Volt(s)";

//obj.GetUnits() returns units to compare
		//strcmp ==0 so strings are identical
		if (strcmp (obj.GetUnits(), ohms) == 0 ) //object is of resistor class
		{
			os <<"Resistor value "<<"("<<obj.GetDescription()<<")";
				return os;
		}

		if (strcmp (obj.GetUnits(), farads) == 0 ) //object is of resistor class
				{
					os <<"Capacitor value "<<"("<<obj.GetDescription()<<")";
								return os;
				}
		if (strcmp (obj.GetUnits(), volts) == 0 ) //object is of resistor class
				{
					os <<"Battery value "<<"("<<obj.GetDescription()<<")";
								return os;
				}


	os <<"("<<obj.GetDescription()<<")"; //some return value outside of if blocks

	return os;
}
};

#endif /* ELECTRONICCOMPONENT_H_ */
