/*
 * Resistor.h
 *
 *  Created on: Mar 15, 2018
 *      Author: Varika
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_





#include "ElectronicComponent.h"

class Resistor : public Electronic_Component
{
private:
	double resistorValue;
public:

	Resistor () //default constructor
{

}

 Resistor(double &resistor_value)//constructor with parameter defined INLINE
	{
		resistorValue = resistor_value;
	}

	virtual double GetValue() ;

	virtual const char* GetUnits() ;

	virtual const char* GetDescription() ;

    virtual ~Resistor();   // destructor



};



#endif /* RESISTOR_H_ */
