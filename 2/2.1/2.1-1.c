// Illustrate the operation of insertion sort on the array A = {31, 41, 59, 26, 41, 58}

#include <stdio.h>

int main(){
	int A[] =  {31, 41, 59, 26, 41, 58};
	int i,j, key;
	for(j=1;j<6;j++){
		key = A[j];
		i = j-1;
		while(i>=0 && A[i]>key){
			A[i+1] = A[i];
			i = i-1;
			A[i+1] = key;
		}
	}
	for(i=0;i<6;i++){
		printf("%d ", A[i]);
	}
}