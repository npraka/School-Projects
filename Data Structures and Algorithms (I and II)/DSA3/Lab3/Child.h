#ifndef CHILD_H
#define CHILD_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Lab342.h"
using namespace std;


class Child
{
	friend ostream& operator<<(ostream &out, Child &print);
	friend istream& operator>>(istream &in, Child &input);

public:
	Child();
	~Child();
	Child(string fName, string lName, int a);
	Child(const Child &second);

	Child& operator=(const Child &second);
	bool operator==(const Child &second) const;
	bool operator!=(const Child &second) const;
	bool operator>(const Child &second) const;
	bool operator<(const Child &second) const;
	bool operator>=(const Child &second) const;
	bool operator<=(const Child &second) const;
	string getLastName() const;

private:
	string firstName, lastName;
	int age;
};

#endif