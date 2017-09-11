#include <iostream>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

// Design an algorithm to find the kth number such that the only prime factors are 3,
// 5, and 7.

int numberk(int k){

	if(k<0)	return 0;

	queue<int> q3;
	queue<int> q5;
	queue<int> q7;

	int val = 0;
	q3.push(1);

	for(int i=1;i<=k;i++){
		// cout << q3.size() << endl;
		
		int v3 = q3.size() > 0 ? q3.front():INT_MAX;
		int v5 = q5.size() > 0 ? q5.front():INT_MAX;
		int v7 = q7.size() > 0 ? q7.front():INT_MAX;

		val = min(v3, min(v5, v7));
		if(val == v3){
			// cout << val << "endl";
			q3.pop();
			q3.push(3*val);
			q3.push(5*val);
		}
		else if(val == v5){
			q5.pop();
			q5.push(5*val);	
		}
		else if(val == v7){
			q7.pop();
		}
		q7.push(7*val);
	}

	return val;
}

int main(){
	int k;
	cout << "k: ";
	cin >> k;

	// queue<int> q;
	// q.push(k);
	// cout << q.front() << endl;

	// cout << INT_MAX << endl;
	cout << numberk(k) << endl;	
	return 0;
}