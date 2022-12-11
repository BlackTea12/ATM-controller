#include <iostream>
#include "Bank.h"

using namespace std;

int main()
{
	/* ATM system */
	unordered_map<string, Bank> admin;

	/* personal information 1 */
	string card_num = "1234";
	string pin = "robot";
	unordered_map<string, int> accounts = { {"a", 100}, {"b", 5}, {"c", 23} };
	Bank Sally(card_num, pin, accounts);	//user name
	/**********************/
	//temporary inserting for two users
	admin.insert({ card_num , Sally });

	/* personal information 2 */
	card_num = "3214";
	pin = "cat";
	accounts.clear();
	accounts = { {"a", 20}, {"b", 500}, {"c", 7} };
	Bank John(card_num, pin, accounts);	//user name
	/**********************/
	//temporary inserting for two users
	admin.insert({ card_num, John });

	// main system
	/* Inserting Card */
	card_num = "";
	pin = "";
	cout << "***************************" << endl;
	cout << "Welcome to our system!\n";
	cout << "Insert your card: ";
	cin >> card_num;

	/* Entering PIN number */
	cout << "Enter your card's PIN number: ";
	cin >> pin;
	while (!admin[card_num].enterPIN(pin)) {
		cout << "Enter your card's PIN number again: ";
		cin >> pin;
	}

	/* Selecting Account */
	admin[card_num].selectAccount();

	int option = 0;
	/* Selecting Action*/
	while (option != 4) {
		cout << "--------------------" << endl;
		cout << "Select action.\n";
		cout << "\t1. Balance\n";
		cout << "\t2. Deposit\n";
		cout << "\t3. Withdraw\n";
		cout << "\t4. Quit\n";
		cout << "Enter number: ";
		cin >> option;

		switch (option)
		{
		case 1:
			admin[card_num].Balance();
			break;
		case 2:
			admin[card_num].Deposit();
			break;
		case 3:
			admin[card_num].Withdraw();
			break;
		case 4:
			break;
		}
	}

	cout << "***************************" << endl;
	cout << "Thank you for using our ATM!\n";
	cout << "Exiting..." << endl;
	cout << "***************************" << endl;

	return 0;
}
