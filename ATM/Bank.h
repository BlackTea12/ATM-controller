#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Bank
{
private:
	string PIN_num;
	unordered_map<string, int> accounts;	// user's accounts {account name, money}
	string user_sel;						// user choice of account

public:
	string card_num;					// unique card number
	Bank() {};
	Bank(string card, string pin, unordered_map<string, int> acnt);	// temporary making bank for test
	void Balance();						// show balance
	void Deposit();						// save money
	void Withdraw();					// withdraw money
	bool enterPIN(string user_input);	// check if PIN is correct or not
	void selectAccount();	// selecting account
};


