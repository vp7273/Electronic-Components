



# Electronic-Components

  PROJECT DESCRIPTION
 *  This program has a base class of electronic component and derived classes that each represent
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




  Programmer created header files
  
 "Resistor.h"
 
 "Capacitor.h"
 
 "Battery.h"


