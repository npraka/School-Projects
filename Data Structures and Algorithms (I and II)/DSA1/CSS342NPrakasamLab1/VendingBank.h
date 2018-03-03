#pragma once
#include <string>
using namespace std;
class VendingBank
{
public:
	VendingBank();
	VendingBank(int id);
	VendingBank(const int pennies, const int nickels, const int dimes, const int quarters, const int halfdollars);
	~VendingBank();
	
	bool setVendingID(const int vendingid);
	bool setVendingName();
	bool InsertPennies(const int pennies);
	bool InsertNickels(const int nickels);
	bool InsertDimes(const int dimes);
	bool InsertQuarters(const int quarters);
	bool InsertHalfDollars(const int halfdollars);
	
	int getVendingBankID() const;
	int getPennies() const;
	int getNickels() const;
	int getDimes() const;
	int getQuarters() const;
	int getHalfDollars() const;
	int getTotal() const;

	int BreakOut();
	int GiveChange(const int change);
	
	
private:
	int numPennies;
	int numNickels;
	int numDimes;
	int numQuarters;
	int numHalfDollars;
	int vendingID;
	string vendingName;
	int total;

};