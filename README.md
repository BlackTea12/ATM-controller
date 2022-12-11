# ATM-controller
Simple ATM controller based on Visual Studio with C++

## :bulb:How to install

__Environment__: Visual Studio 2019 (x86)

1. Clone the repository or download the whole source file as .zip.

2. Next, open the solution file __"ATM.sln"__ in Visual Studio.

3. Execute the program with __'Ctrl + F5'__.

## :star:Instructions

### :one: Overview of the system flow

Solution file provides simple ATM system. 

In this solution, it is assumed that there is a list of Bankers saved in some database, which is temporary declared in the __'ATM.cpp'__. 

First, system is activated with the request of the user's card number. A match will be found from the database(already declared) and continues with entering PIN number.

Second, once the user has the right PIN number entered, the user can select his/her existing account.

Third, with the selected account, the user can choose wheter to Balance, Deposit, Withdraw or Quit.

Last of all, when Quit is selected, the ATM system will end.

### :two: Bank.cpp / Bank.h

In this class, variables of user's PIN number, owned accounts, function selection is included.

- PIN number: (__string__ PIN_num), number that is related to card number.

- owned accounts: (__unordered_map<string, int>__ accounts), accounts that are owned by the user.

- function selection: (__string__ user_sel), Balance/Deposit/Withdraw selection variable.

For important functions are,

- __void__ Balance(): Showing balance of the account that user has selected.

- __void__ Deposit(): Adding money to existing account.

- __void__ Withdraw(): Taking out money from existing account. When the user is trying to withdraw more than the existing amount, then the system refuses to withdraw and request to enter amounts to withdraw again.

- __bool__ enterPIN(string user_input): returns __false__ if PIN is incorrect, __true__ if it is correct.

- __void__ selectAccount(): It shows exisiting accounts and the user has to choose by its name. If the name is misspelled, then the system requires to enter again.

 ### :three: ATM.cpp 
 
 As described in the overview of the system flow, user's information is declared like the following image.
 
 <image src = "https://user-images.githubusercontent.com/41279501/206909698-08f36eb8-2f74-428d-9f80-1b4fac6f5338.png" width="50%" height="50%">
 
 Multiple users' information is managed in,
 
 
    LINE 9) unordered_map<string, Bank> admin;
 
 
__admin__ variable.

ATM system starts with the request of inserting card. It is then followed by entering PIN-> Balance / Deposit / Withdraw / Quit.
