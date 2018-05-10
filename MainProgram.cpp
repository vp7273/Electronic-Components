
//	CS	1337.003 Project	3 <vxp171430>	<Varika Pinnam>

//PROJECT DESCRIPTION
/*  This program has a base class of electronic component and derived classes that each represent
 * a type of electronic component. The user is asked to select a type of electronic component.
 * An object of the selected class (resistor, capacitor, or battery) is created to call the getvalue
 * function of the class. The getvalue function of that class prompts the user for a value of the component
 * and returns that value as a double. Then, the program dynamically allocates a new object of the selected
 * component type and adds it to a vector of pointers to the base class. This works because an object of a derived
 * class has the properties of the base class still. When the object is dynamically created, the value returned from
 * the earlier call to getvalue is passed into the constructor. The program continues to prompt for more
 * component selections and values until the user elects to print. When printing, the overloaded operator <<
 * is used so that when a vector element of type pointer to electronic component is called, it prints the description
 * which is the value of the component stored earlier and the units. Then, the program goes through the vector again, and this
 * time, the overloaded operator operates on a dereferenced pointer to do the same (print description).
 * Finally, a for loop is used to iterate through the vector and delete all the pointers to dynamically allocated memory.
*/



//programmer created header files

// derived classes' declarations
#include "Resistor.h"
#include "Capacitor.h"
#include "Battery.h"

#include <vector> //vector instead of array used
#include <string> //string object

using namespace std;

int main()
{
	vector <Electronic_Component *> ComponentData; //vector of pointers to electronic component


	string userselection;// variable to hold selection of 1-4 from prompt declared outside do-while loop
	//string object to read for input validation if user inputs extraneous characters ex: 1xxx
	int vectorIndex = 0; //vector subscript to access elements


	do {
		cout << "Please enter 1, 2, 3 or 4:" << endl;
		cout << "1 - Enter information about a resistor" << endl;
		cout << "2 - Enter information about a capacitor" << endl;
		cout << "3 - Enter information about a battery" << endl;
		cout << "4 - Print component information and terminate the program" << endl;


		cin >> userselection;
		//input validation
		while ((userselection != "1") && (userselection != "2") && (userselection != "3") && (userselection != "4"))
		{
			cout << "Entry not accepted. Please enter ONLY 1, 2, 3, or 4" << endl <<endl;
			cout << "Please enter 1, 2, 3 or 4:" << endl;
					cout << "1 - Enter information about a resistor" << endl;
					cout << "2 - Enter information about a capacitor" << endl;
					cout << "3 - Enter information about a battery" << endl;
					cout << "4 - Print component information and terminate the program" << endl;

			// clear cin before re-taking input
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> userselection;
		}
		//After user entry for one type of component or printing is accepted...

		//default constructor builds a temporary object to get the value first; the temporary object is later deleted automatically
		//the value is passed into other constructor when new object is created through dynamic memory allocation

		if (userselection == "1") //user chose resistor
		{
			 Resistor tempobj; //temp obj automatically deleted once out of scope
			 double value = tempobj.GetValue();
			 ComponentData.push_back(new Resistor (value));
			 vectorIndex++;

		}
		if (userselection == "2") //user chose capacitor
		{
			Capacitor tempobj; //temp obj automatically deleted once out of scope
			double value = tempobj.GetValue();
			ComponentData.push_back(new Capacitor (value));
			vectorIndex++;

		}
		if (userselection == "3") //user chose battery
		{
			Battery tempobj; //temp obj automatically deleted once out of scope
			double value = tempobj.GetValue();
			ComponentData.push_back(new Battery (value));
			vectorIndex++;

		}


	} while (userselection != "4");

	if (userselection == "4") //user choses print
	{
		for (int count =0; count < vectorIndex; count++) //first iteration to print all component values
		{
			cout<< "Component value is "<<ComponentData[count]<<endl; // << now uses overloaded operator in base class to call getdescription
		}


	}

	cout <<endl;// space between two sets of output

	for (int count =0; count < vectorIndex; count++) //second iteration to print type of component and value
	{
		cout << "Component " << count+1 << " " //count+1 because output starts at value of 1 instead of subscript 0
				<< *ComponentData[count] << endl; //second definition of overloaded << for dereferenced pointer
	}


	for (int count =0; count < vectorIndex; count++) //Deleting dynamically allocated memory
	{
		delete ComponentData[count];
		ComponentData[count] = nullptr;

	}


	return 0;
}


