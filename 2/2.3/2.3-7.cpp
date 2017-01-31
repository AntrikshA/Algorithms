// Need to make this O(n) instead of O(n logn) -- other than merge sort

#include <iostream>
#include "sort.h"
using namespace std;

void sumx(int S[], int x, int n){
	int i=0, j=n-1;
	while(i<j){
		if(S[i]+S[j]==x){
		    cout << i << ", " << j << ", " << S[i] << " + " << S[j] <<  endl;
		    return 0;
		}
		else if(S[i]+S[j] != x){
		    if(S[j] > (x-S[i])){
			j--;
			continue;
		    }
		    if(S[i] < (x-S[j])){
			i++;
			continue;
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
