#include <iostream>
#include "sort.h"
using namespace std;

void sumx(int S[], int x, int n){
	for (int i = 0; i < n; i++){
		int key = x-S[i];
		int p=i+1;
		int r = n;
		while(p<r){
			int q = (p+r)/2;
			if (S[q]<key){
				p=q+1;
			}
			else if(S[q]>key){
				r=q-1;
			}
			else{
				cout << S[i] << "+" << S[q] <<  endl;
				return;
			}
		}
	}
	cout << "No two numbers sum to " << x << endl;
	return;
}

int main(){
	int n;
	cout << "No. of numbers "; 
	cin >> n;
	int k=n;
	int S[n];
	while(n--){
		cin >> S[k-n-1];
	}
	*S = merge_sort(S,0,n);

	int x;
	cout << "Required sum: ";
	cin >> x;
	sumx(S,x,k);
}