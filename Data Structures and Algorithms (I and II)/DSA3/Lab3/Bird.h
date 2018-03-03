#ifndef BIRD_H
#define BIRD_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Lab342.h"

class Bird
{
	friend ostream& operator<<(ostream &out, Bird &print);
	friend istream& operator>>(istream &in, Bird &input);


public:
	Bird();
	~Bird();
	Bird& operator=(const Bird &second);
	bool operator==(const Bird &second) const;
	bool operator!=(const Bird &second) const;
	bool operator>(const Bird &second) const;
	bool operator<(const Bird &second) const;
	bool operator>=(const Bird &second) const;
	bool operator<=(const Bird &second) const;
	Bird(const Bird &other);

private:
	string name;
	int iD;
};

#endif