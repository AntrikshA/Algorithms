#include <iostream>
#include <cmath>
using namespace std;

// Given a positive integer, print the next smallest and the next largest number that
// have the same number of 7 bits in their binary representation

int bintodec(string a){
	int k=0;
	int ans = 0;
	for(int i=(a.length()-1);i>=0;i--){
		ans += (a[i]-'0')%10 * pow(2,k);
		k++;
	}
	return ans;
}

void dectobin(int num){
    int rem;
    
    if (num <= 1){
        cout << num;
        return;
    }

    rem = num % 2;
    dectobin(num / 2);
    cout << rem;
}

int next(int num){
	int temp = num;
	int c0 = 0;
	int c1 = 0;
	while((temp&1) == 0){
		c0++;
		temp = temp >> 1;
	}
	while((temp&1) == 1){
		c1++;
		temp = temp >> 1;
	}

	int mask = (1 << (c0+c1));
	int hidemask = ~((1 << (c0+c1)) - 1);

	num = ((num|mask)&hidemask);
	num = num|((1 << (c1-1)) - 1);

	dectobin(num);
	cout << endl;

	return num;
}

int prev(int num){
	int temp = num;
	int c0 = 0;
	int c1 = 0;
	while((temp&1) == 1){
		c1++;
		temp = temp >> 1;
	}
	while((temp&1) == 0){
		c0++;
		temp = temp >> 1;
	}
	int hidemask = ~((1 << (c0+c1+1)) - 1);
	int c = ((1 << (c1+1)) - 1) << (c0-1);

	num = ((num)&hidemask);
	num = num|c;

	dectobin(num);
	cout << endl;

	return num;


}

int main(){
	string num;
	cout << "num: ";
	cin >> num;
	// cout << num << endl;
	int number = bintodec(num);
	dectobin(number);
	cout << endl;
	cout << number << endl;
	cout << next(number) << endl;
	cout << prev(number) << endl;
	return 0;
}