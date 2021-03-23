#include <iostream>
using namespace std;

// CONSTRUCTORS: 
// A constructor is a member function that is automatically called when an object of that 
// class is declared. Used to initialize the value of the variables.

// highlights:
// **has the same name as the class
// **no return type (not even void)
// **constructors should always be declared as public (or else the class is useless)
// **constructors are usually overloaded to allow objects to be initialized in more than one way

// Class for BankAccount using constructors instead of set as in the previous exercise.
class BankAccount
{
public:
	// overloaded constructors
	BankAccount(int dollars, int cents, double rate);
	BankAccount(int dollars, double rate);
	BankAccount();
	// other member functions
	void set(int dollars, int cents, double rate);
	void set(int dollars, double rate);
	void update(); /* update after one year of interest has been added to account balance */

	double get_balance(); /* returns the current balance */
	double get_rate(); /* returns the current interest rate */
	void output(ostream& outs);
	// if outs is an file output stream then outs has already been connected to a file
	// writes account balance and interest rate to stream outs.
private:
	double balance;
	double interest_rate;

	double fraction(double percent); /* converts percentage to a fraction... ex: 50.3% is 0.503 */
};

int main()
{
	BankAccount account1(100, 2.3), account2; /* notice there are no parenthesis if the arguments are empty */
	account1.output(cout);
	cout << "account2 initialized as follows:\n";
	account2.output(cout);

	account1 = BankAccount(999,99,5.5); /* account1 reassigned new values using the constructor */
	cout << "account1 reset to the following: \n";
	account1.output(cout);
	return 0;
}

// constructor definitions:
BankAccount::BankAccount(int dollars, int cents, double rate)
{
	if ((dollars < 0) || (cents < 0) || (rate < 0))
	{
    	cout << "Illegal values for money or interest rate.\n";
		exit(1);
	}
	balance = dollars + 0.01 * cents;
	interest_rate = rate;
}

BankAccount::BankAccount(int dollars, double rate)
{
	if ((dollars < 0) || (rate < 0))
	{
    	cout << "Illegal values for money or interest rate.\n";
		exit(1);
	}
	balance = dollars;
	interest_rate = rate;
}

BankAccount::BankAccount()
{
	// intentionally blank constructor
}

void BankAccount::set(int dollars, int cents, double rate)
{
	if(dollars < 0 || cents < 0 || rate < 0)
	{
		cout << "illegal values for money or interest rate \n";
		exit(1);
	}
	balance = dollars + 0.01 * cents;
	interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
	if(dollars < 0 || rate < 0)
	{
		cout << "illegal values for money or interest rate \n";
		exit(1);
	}
	balance = dollars;
	interest_rate = rate;
}

void BankAccount::update()
{
	balance = balance + fraction(interest_rate) * balance;
}

double BankAccount::fraction(double percent_value)
{
	return (percent_value / 100.0);
}

double BankAccount::get_balance()
{
	return balance;
}

double BankAccount::get_rate()
{
	return interest_rate;
}

void BankAccount::output(ostream& outs)
{
	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	outs.precision(2);
	outs << "account balance $" << balance << endl;
	outs << "interest rate " << interest_rate << "%" << endl;
}




























