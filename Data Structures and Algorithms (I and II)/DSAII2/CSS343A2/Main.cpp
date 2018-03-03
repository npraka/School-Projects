#include "WordTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

	ifstream File;
	//File.open("bacon.txt");
	
	WordTree H;

	int asciiVal=0; //represents current ascii get value for assessment
	string curWord = ""; //Will be the word to get added by Add() and then reset to ""



	//H.Add("Bacon, Kevin (I)", "SPACEX");
	//cout << H << endl;

	while (!File.eof())//While still taking in input
	{
		asciiVal = File.get();//After process for character is completed, go to next character
		


		while (asciiVal < 123 && asciiVal > 64)//Last Name
		{

			curWord += asciiVal;
			

			asciiVal = File.get();
			

		}
		if (asciiVal == 44)
		{
			curWord += asciiVal;
		}

		
		cout << curWord << endl;
        
		
		curWord = "";

		//asciiVal = File.get();
		//if (asciiVal == 32)
		//{

		//	asciiVal = File.get();
		//while (asciiVal < 123 && asciiVal > 64)//First Name
		//{

		//	curWord += asciiVal;


		//	asciiVal = File.get();


		//}
		//


		//}
		//cout << "First Name: ";
		//cout << curWord << endl;
		//asciiVal = File.get();
	 //    if (asciiVal ==32 )
		//{
		//	 asciiVal = File.get();
		//	 if (asciiVal==28)
		//	 {
		//		 curWord += asciiVal;
		//		 asciiVal=File.get();
		//		 
		//		 while (asciiVal != 29)
		//		 {
		//			 curWord += asciiVal;
		//			 asciiVal = File.get();
		//		 }
		//			 

		//	 }
		//}
		// cout << curWord << endl;
		//curWord = "";
		//while (asciiVal==9)
		//{


		//	cout << " TAB " << endl;
		//	asciiVal=File.get();


		//}
		//
		//
		//
		//while (asciiVal!=32)//Movie 
		//{
		//	
		//	curWord += asciiVal;
		//	asciiVal = File.get();

		//	


		//}

		//cout << "Movie: " ;
		//cout << curWord<<endl;

		

		

		

	}
	//////////////////////////////////////////////////////////////////////

	

}
	

