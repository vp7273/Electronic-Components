/*
 * Capacitor.h
 *
 *  Created on: Mar 16, 2018
 *      Author: Varika
 */

#ifndef CAPACITOR_H_
#define CAPACITOR_H_


#include "ElectronicComponent.h"

class Capacitor : public Electronic_Component
{
private:
	double capacitorValue;

public:

	Capacitor ()//default constructor
{

}

	Capacitor(double &capacitor_value) //constructor with parameter defined INLINE
	{
		capacitorValue = capacitor_value;
	}

	virtual double GetValue();

	virtual const char* GetUnits();

	virtual const char* GetDescription();

	virtual ~Capacitor(); //  destructor

};



#endif /* CAPACITOR_H_ */
