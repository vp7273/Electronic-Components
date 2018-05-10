/*
 * Battery.h
 *
 *  Created on: Mar 16, 2018
 *      Author: Varika
 */

#ifndef BATTERY_H_
#define BATTERY_H_


#include "ElectronicComponent.h"

class Battery: public Electronic_Component
{
private:
	double batteryValue;

public:

	Battery () //default constructor
{

}

	Battery(double &battery_value) //constructor with parameter defined INLINE
{
		batteryValue = battery_value;
}

	virtual double GetValue();

	virtual const char* GetUnits();

	virtual const char* GetDescription();

	virtual ~Battery(); // virtual destructor

};




#endif /* BATTERY_H_ */
