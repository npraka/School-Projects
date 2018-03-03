

#include <iostream>
#include "TimeSpan.h"
using namespace std;
void main()
{
	//Testing All constructors
	TimeSpan Nothing();

	TimeSpan Test1(1, 70, 61);
	cout << " TimeSpan Test1(1, 70, 61) is " << Test1;

	TimeSpan Test2(-70, 61);
	cout << " TimeSpan Test2( -70, 61); is " << Test2;
	
	TimeSpan Test3(350);
	cout << "TimeSpan Test3(350) is" << Test3;
	
	TimeSpan Test4(1.5, 70.0, 61.0);
	cout << " TimeSpan Test4(1.5, 70.0, -61.0) is " << Test4;
	
	TimeSpan Test5(361.68);
	cout << " TimeSpan Test5(361.68) is " << Test5;
	
	TimeSpan Test6(4.5,361.68);
	cout << " TimeSpan Test6(4.5,361.68) is " << Test6;
	
	TimeSpan Test7(1.6, 70, 61);
	cout << " TimeSpan Test7(1.6, 70, 61) is " << Test7;
	
	TimeSpan Test8(1.5, 7.0, 61);
	cout << " TimeSpan Test8(1.5, 7.0, 61) is " << Test8;
	
	TimeSpan Test9(1, 2, 3.6);
	cout << " TimeSpan Test9(1, -2, 3.6) is " << Test9;
	
	TimeSpan Test10(1, 2.5, 3.6);
	cout << " TimeSpan Test10(1, 2.5, 3.6) is " << Test10;
	
	TimeSpan Test11(1, 2.5, 3);
	cout << " TimeSpan Test11(1, 2.5, -3) is " << Test11;
	
	TimeSpan Test12(1.5, 2, 3.6);
	cout << " TimeSpan Test12(1.5, 2, 3.6) is " << Test12;
	
	TimeSpan Test13(12, 2.5);
	cout << " TimeSpan Test13(12, 2.5) is " << Test13;
	
	TimeSpan Test14(4.5, 3);
	cout << " TimeSpan Test14(4.5, 3) is " << Test14;

	cout << "Test10 is " << Test10.getHours() << " " << Test10.getMinutes() << " " << Test10.getSeconds() << endl;

	TimeSpan Compare(1, 1, 1);
	TimeSpan Compare2(2, 2, 2);

	cout << "Compare + Compare2 is "<< Compare + Compare2 << endl;
	cout << "Compare - Compare2 is " << Compare - Compare2 << endl;
	cout << "-Compare2 is" << -Compare2 << endl;
	if (Compare == Compare)
	{
		cout << "Compare==Compare"<<endl;
		Compare += Compare2;
		cout << Compare << endl;
	}
	if (Compare != Compare2)
	{	
		cout << "Compare!=Compare2" << endl;
		cout << Compare2 << endl;
		Compare = Compare2;
		Compare2 -= Compare;
		cout << Compare2;
	}

}