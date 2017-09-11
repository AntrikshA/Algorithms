#include <iostream>

using namespace std;

// Write a method to replace all spaces in a string with '%20'. You may assume that the
// string has sufficient space at the end of the string to hold the additional characters,
// and that you are given the "true" length of the string. (Note: if implementing in Java,
// please use a character array so that you can perform this operation in place.)

string replace(string str){
	string newStr = "";
	int flag=0;
	for(int i=str.length()-1;i>=0;i--){
		if(str[i]!=' ' && flag==0)
			flag=1;
		if(flag==1 && str[i]==' '){
			newStr = "%20" + newStr;
		}
		else if(str[i] != ' ' && flag==1)
			newStr = str[i] + newStr;
	}
	return newStr;
}

int main(){
	string str = "hello and welcome to our first hoolicon";

	cout << replace(str) << endl;

	return 0;
}