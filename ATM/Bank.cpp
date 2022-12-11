#include "Bank.h"

Bank::Bank(string card, string pin, unordered_map<string, int> acnt)
{
	card_num = card;						
	PIN_num = pin;
	accounts = acnt;	
	user_sel = acnt.begin()->first;						
}

void Bank::Balance()
{
	cout << "--------------------" << endl;
	cout << "Balance: " << accounts[user_sel] << endl;
}

void Bank::Deposit()
{
	int money = 0;
	cout << "--------------------" << endl;
	cout << "Enter amounts to be deposited: ";
	cin >> money;
	accounts[user_sel] += money;
}

void Bank::Withdraw()
{
	int money = 0;
	cout << "--------------------" << endl;
	cout << "Enter amounts to be withdrawed: ";
	cin >> money;

	while (true)
	{
		if (money > accounts[user_sel]) {
			cout << "Unable to withdraw. (Balance of your account: " << accounts[user_sel] << ")\n";
			cout << "Enter amounts to withdraw: ";
			cin >> money;
		}
		else {
			accounts[user_sel] -= money;
			break;
		}
	}
}

bool Bank::enterPIN(string user_input)
{
	if (user_input != PIN_num) {
		cout << "Wrong PIN number entered!" << endl;
		return false;
	}
	else
		return true;
}

void Bank::selectAccount()
{
	string user_acnt = "";

	cout << "--------------------" << endl;
	cout << "Select your Account" << endl;
	for (auto iter = accounts.begin(); iter != accounts.end(); iter++)
		cout << iter->first << endl;

	cout << "\nEnter account name: ";
	cin >> user_acnt;
	while (accounts.find(user_acnt) == accounts.end()) {
		cout << "Failed to access... Please check again.\n";
		cout << "Enter account name: ";
		cin >> user_acnt;
	}

	cout << "\nSelected Account: " << user_acnt << endl;
	user_sel = user_acnt;
}
