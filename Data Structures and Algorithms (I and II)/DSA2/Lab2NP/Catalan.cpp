
#include <iostream>
using namespace std;


int Catalan(int N);

int main()
{

	int i = 0;
	while (i >= 0)
	{

		cout << "Choose an integer to see its Catalan Number or choose a negative number to quit. " << endl;
		cin >> i;
		if (i >= 0)
		{
			cout << "The Catalan number for " << i << " is " << Catalan(i) << endl;
		}
	}
	return 0;
}

int Catalan(int N)
{
	if (N < 0)
	{
		return -1;
	}
	if (N == 0||N==1)
	{

		return 1;
	}
	if (N>0)
	{

		int CatalanNumber = 0;
		for (int i = 0; i < N; i++)
		{
			CatalanNumber += Catalan(i)*Catalan(N - i-1);

		}
		return CatalanNumber;
		
	}
}
