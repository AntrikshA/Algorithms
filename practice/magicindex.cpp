#include <iostream>
#include <cmath>

using namespace std;

// A magic index in an array A[l.. .n-l] is defined to be an index such that A[i] =
// i. Given a sorted array of distinct integers, write a method to find a magic index, if
// one exists, in array A.
// FOLLOW UP
// What if the values are not distinct?

int magicindex(int array[]){
	int start = 0;
	int end = sizeof(array) / sizeof(array[0]);

	while(start<end){
		int mid = (start+end)/2;
		if(mid == array[mid])
			return mid;
		else if(array[mid] < mid){
			end = min(array[mid], mid-1);
		}
		else if(array[mid]>mid){
			start = max(array[mid], mid+1);
		}
	}

}

int main(){
	int array[] = {-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};

	cout << magicindex(array) << endl;

	return 0;
}