#include <iostream>

using namespace std;

int checkdiff(int a, int b){
	int counter = 0;
	int i=32;
	while(a||b){
		int mask = (~0 << i) - 1;
		bool atest = a|mask;
		bool btest = b|mask;
		// cout << atest << " " << btest << endl;
		if ((a|mask) != (b|mask)){
			counter++;
		}
		a = a >> 1;
		b = b >> 1;
	}
	return counter;

}

int bitswap(int a, int b){
	int c = a^b;
	int counter = 0;
	while(c){
		counter+= c&1;
		c = c >> 1;
	}
	return counter;
}

int main(){
	int a, b;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	cout << checkdiff(a, b) << endl;
	cout << bitswap(a, b) << endl;

	return 0;
}