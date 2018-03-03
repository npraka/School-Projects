#pragma once
#include <string>

#include <iostream>
#include <fstream>
using namespace std;
class ABST
{
public:
	ABST();
	~ABST();
	bool AddActor(string s);
	bool AddMovie(string a);
	friend ostream& operator<<(ostream& os, ABST& dt);
private:

	struct Vertex {
		string actor[3];
		string movies[100];
			
	};

	struct Edge {


	};
};

