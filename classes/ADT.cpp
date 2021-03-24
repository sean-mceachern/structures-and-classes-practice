#include <iostream>
#include <cmath>
using namespace std;

// Abstract Data Type: a data type is referred to as an abstract data type (ADT) if the programmer doesn't have access to 
// how the values and operations of that data type are implemented.

//** for example -- the int data type is abstract because the programmer doesn't know how the operators like + and * are implemented (or doesn't need to know)
//** to make a defined class an ADT the class must be implemented in a certain way

// ** 3 common rules for ensuring the class is an ADT:
//  1. Make all the member variables private members of the class
//  
//  2. Make each of the basic operations that the programmer needs 
//     a public member function of the class, and fully specify how 
//     to use each such public member function.
// 
//  3. Make any helping functions private member functions
// 
// ** the "interface" of the ADT is all of the public members plus comments on how to use them


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
	int dollars_part;
	int cents_part;
	double interest_rate; /*expressed as a fraction*/

	double fraction(double percent);/*converst a percentage to a frac*/
	double percent(double fraction_value);/*converts frac to percent*/
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

// Instead of using the fraction() in update() as before, fraction() is
// instead used in the definition of the constructors as to follow the ADT defintion.
BankAccount::BankAccount(int dollars, int cents, double rate)
{
	if((dollars <0) || (cents < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate. \n";
		exit(1);
	}
	dollars_part = dollars;
	cents_part = cents;
	interest_rate = fraction(rate);
}

BankAccount::BankAccount(int dollars, double rate)
{
	if((dollars <0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate. \n";
		exit(1);
	}
	dollars_part = dollars;
	cents_part = 0;
	interest_rate = fraction(rate);
}

BankAccount::BankAccount(): dollars_part(0), cents_part(0),interest_rate(0.0)
{
	// intentionally blank
}

double BankAccount::fraction(double percent_value)
{
	return (percent_value/100.0);
}

// uses cmath lib
void BankAccount::update()
{
	double balance = balance + interest_rate * balance;
	dollars_part = static_cast<int>(floor(balance));
	cents_part = static_cast<int>(floor((balance - dollars_part)*100));
}

double BankAccount::get_balance()
{
	return (dollars_part + 0.01 * cents_part);
}
double BankAccount::percent(double fraction_value)
{
	return (fraction_value * 100);
}
double BankAccount::get_rate()
{
	return percent(interest_rate);
}

// Uses iostream lib
void BankAccount::output(ostream& outs)
{
	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	outs.precision(2);
	outs << "account balance $" << get_balance() << endl;
	outs << "interest rate " << get_rate() << "%" << endl;
}

void BankAccount::set(int dollars, int cents, double rate)
{
	if((dollars < 0) || (cents < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate.\n";
		exit(1);
	}

	dollars_part = dollars;
	cents_part = cents;
	interest_rate = fraction(rate);
}

void BankAccount::set(int dollars, double rate)
{
	if((dollars < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate.\n";
		exit(1);
	}

	dollars_part = dollars;
	interest_rate = fraction(rate);
}




















