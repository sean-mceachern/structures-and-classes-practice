#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int main (){
	ifstream in_stream;
	ofstream out_stream;
	
	in_stream.open("infile.dat");
	if(in_stream.fail())
	{
		cout << "input file opening failed. \n" ;
		exit(1);
	}

	out_stream.open("infile.dat");
	if(out_stream.fail())
	{
		cout << "output file opening failed. \n" ;
		exit(1);
	}

	int first, second, third;
	in_stream >> first >> second >> third;
	out_stream << "the sum of the first 3\n"
				  "numbers in infile.dat\n"
				  "is" << (first + second + third)
				  << endl;
	in_stream.close();
	out_stream.close();
	return 0; 
}