#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define FILE "klines.cpp"

using namespace std;

// Write a method to print the last K lines of an input file using C++.

void print(ifstream infile, int k, int count){

	infile.open(FILE);

	string line;
	while (getline(infile, line))
	{
	    istringstream iss(line);
	    int a, b;
	    if (!(iss >> a >> b)){
		    break;
	    } // error

	    cout << a << " " << b << endl;
	    // process pair (a,b)
	}
}


int main(){
	ifstream myReadFile;
	int k=10;

	print(myReadFile, k, 0);

	return 0;
	
}