#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

// The below code is notes and exercises from the textbook Problem Solving With C++. Chapter 10, Defining Classes


// DOT OPERATOR-----------------------------------------------------------
// struct Student_Record /*class definition*/
// {
// 	// member variables
// 	int student_number;
// 	char grade;
// };
// int main() 
// {
// 	Student_Record your_record; /*structure variable declared*/
// 	your_record.student_number = 12345;
// 	your_record.grade = 'F';
// }
// end--------------------------------------------------------------------


// HIERARCHICAL STRUCTURES------------------------------------------------
// struct Date 
// {
// 	int month;
// 	int day;
// 	int year;
// };
// struct PersonInfo
// {
// 	double hieght;
// 	int wieght;
// 	Date birthday;
// };
// int main(){
// 	PersonInfo person1;
// 	cout << person1.birthday.year; /* has type dirthday, which is type Date */
// }
// end--------------------------------------------------------------------


// CLASSES WITH MEMBER FUNCTIONS && Private vs. Public -------------------
// class DayOfYear
// {
// public:
// 	void output(); /* member function declaration. will function as output*/
// 	void 
	
// private: /* all objects should be declared private and only methods should be declared public.
// 			The methods that are public which manipulate or change values of objects are known as mutators */
// 	int month;
// 	int day;

// };

// int main()
// {
// 	DayOfYear today, birthday;
	
// 	cout << "enter the month (as a number please): \n";
// 	cin >> today.month;
// 	cout << "enter the date of the month: \n";
// 	cin >> today.day;

// 	cout << "enter your birthday month (as a number please): \n";
// 	cin >> birthday.month;
// 	cout << "enter the date of your birthday: \n";
// 	cin >> birthday.day;

// 	cout << "Today's date is: \n";
// 	today.output();

// 	cout << "Your birthday is: \n";
// 	birthday.output();

// 	if(today.month == birthday.month
// 		&& today.day == birthday.day)
// 		cout << "Happy Birthday! \n";
// 	else
// 		cout << "it's not your birthday :( \n";

// 	return 0;
// }
// // defining the member function
// void DayOfYear::output()
// {
// 	cout << "month = " << month
// 		 << "day = " << day << endl;
// }
// end ----------------------------------------------------------------

// EXAMPLE USING BankAccount Class from 10.5---------------------------

// this program will set up bank accounts and update them with different balances and interests rates.
// the point of this exercise is to better understand how public methods (mutators) manipulate private variables.

// define class BankAccount
class BankAccount
{
	// only methods which mutate private objects should be public
public:
	void set(int dollars, int cents, double rate);
	// $dollars.cents
	// interest rate
	void set(int dollars, double rate); /* the member function "set" is overloaded to account for an input that doesn't include cent */
	// $dollars.00
	// interest rate
	void update();
	double get_balance();
	double get_rate();
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
	BankAccount account1, account2;
	cout << "start of test: \n";
	account1.set(123,99,3.0);
	cout <<"account1 initial statement: \n";
	account1.output(cout);
	account1.set(100,5.0);   /* overloaded memeber functions */
	cout << "account1 with new setup: \n";
	account1.output(cout);

	account1.update();
	cout << "account1 after update: \n";
	account1.output(cout);

	account2 = account1;
	cout << "account2: \n";
	account2.output(cout);

	return 0;
}
// public method definitions
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









