#include "Bird.h"


Bird::Bird()
{
}


Bird::~Bird()
{
}
Bird& Bird::operator=(const Bird &second)
{
	if (this != &second)
	{
		name = second.name;
		iD = second.iD;

	}
	return *this;
}
bool Bird::operator==(const Bird &second) const
{
	return(name == second.name&&iD == second.iD);
}
bool Bird::operator!=(const Bird &second) const
{
	if (*this == second)
	{
		return false;
	}
	return true;
}
bool Bird::operator>(const Bird &second) const
{
	return (name > second.name || iD > second.iD);

}
bool Bird::operator<(const Bird &second) const
{
	if(*this > second)
	{
		return false;
	}
	return true;
}
bool Bird::operator>=(const Bird &second) const
{
	return(*this > second || *this == second);
}
bool Bird::operator<=(const Bird &second) const
{
	return(*this < second || *this == second);
}
Bird::Bird(const Bird &other)
{
	*this = other;
}
ostream& operator<<(ostream &out, Bird &print)
{
	out << print.name << "     " << print.iD << endl;
	return out;
}
istream& operator>>(istream &in, Bird &input)
{

	in >> input.name >> input.iD;
	return in;

}