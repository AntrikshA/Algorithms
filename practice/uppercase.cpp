// #include <boost/algorithm/string.hpp>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){

	string str = "Hello World";

	for(auto &c: str){
		c = toupper(c);
		cout << c;
	}

	cout << endl << str << endl;

	// cout << std::transform(str.begin(), str.begin(), str.end(), std::toupper) << endl;

	// cout << boost::to_upper(str) << endl;

	// cout << boost::to_upper_copy<string>(str) << endl;

	return 0;	

}