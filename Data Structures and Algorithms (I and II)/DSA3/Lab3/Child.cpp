#include "Child.h"




Child::Child()
{

}


Child::~Child()
{
}

Child::Child(string fName, string lName, int a)
{
	firstName = fName;
	lastName = lName;
	age = a;

}

Child&  Child::operator=(const Child &second) 
{
	if (this != &second)
	{
		firstName = second.firstName;
		lastName = second.firstName;
		age = second.age;
		
	}
	return *this;
}

ostream& operator<<(ostream &out, Child &print)
{
	cout << print.firstName << " " << print.lastName << "    " << print.age << endl;
	return out;
}

istream& operator>>(istream &in, Child &input)
{
	in >> input.firstName >> input.lastName >> input.age;
	return in;
}



bool Child::operator==(const Child &second) const
{
	if (firstName == second.firstName && lastName == second.lastName && age == second.age)
		return true;
	else
	return false;
}
bool Child::operator!=(const Child &second) const
{
	return(*this == second);
	
}
bool Child::operator>(const Child &second) const
{
	return (lastName > second.lastName && firstName > second.firstName && age>second.age);
		
}

bool Child::operator<(const Child &second) const
{
	return (lastName < second.lastName && firstName < second.firstName&&age<second.age);
}


bool Child::operator>=(const Child &second) const
{
	return (*this == second || *this>second);

}

bool Child::operator<=(const Child &second) const
{
	return (*this == second || *this<second);
}

string Child::getLastName() const
{
	return lastName;
}


Child::Child(const Child &second)
{
	*this = second;
}
