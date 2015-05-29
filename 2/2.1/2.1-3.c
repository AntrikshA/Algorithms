/*
Consider the searching problem:
Input: A sequence of n numbers A = {a1 ; a2 ; : : : ; an} and a value v.
Output: An index i such that v = A[i] or the special value NIL if v does not appear in A.

Write pseudocode for linear search, which scans through the sequence, looking
for v. Using a loop invariant, prove that your algorithm is correct. Make sure that
your loop invariant fulfills the three necessary properties.
*/

#include <stdio.h>

int main(){
	int i, n, v, flag;
	int A[100];
	printf("\nEnter the value of n : ");
	scanf(" %d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter A[%d] : ",i);
		scanf(" %d",&A[i]);
	}
	printf("\nEnter the value v : ");
	scanf(" %d",&v);
	flag = 0;
	for(i=0;i<n;i++){
		if (A[i] == v){
			printf("Found at %d\n", i);
			flag = 1;
		}
	}
	if(flag==0){
		printf("Sorry, the number you entered was not in the list !\n");
	}
}