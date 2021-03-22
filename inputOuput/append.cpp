#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	cout << "Opening append.txt for appending.\n";
	ofstream fout;
	fout.open("append.txt", ios::app);
	if(fout.fail())
	{
		cout << "Error opening the specified file.\n";
		exit(1);
	} 
	fout << "5 6 pick up sticks\n"
		 << "7 8 c++ is fucking great!\n";

	fout.close();
	cout << "end of file appending\n";

	return 0;
}