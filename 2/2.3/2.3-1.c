/* Using Figure 2.4 as a model, illustrate the operation of merge sort on the Aay
A = {3; 41; 52; 26; 38; 57; 9; 49}.
*/

#include <stdio.h>

int A[] = {3, 41, 52, 26, 38, 57, 9, 49};

int merge_sort(int p, int r ){
	int q;
	if(p<r){
		q=((p+r)/2);
		merge_sort(p,q);
		merge_sort(q+1,r);
		merge(p,q,r);	
	}
		
}

int merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    // create temp Arrays 
    int L[n1], R[n2];
 
    // Copy data to temp Arrays L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1+ j];
 
    // Merge the temp arrays back into A[l..r]
	i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any 
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any 
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

int main(){
	int i;
	printf("Unsorted : \n");
	for(i=0;i<8;i++){
		printf("A[%d] : %d\n",i+1,A[i]);
	}
	merge_sort(0,7);
	printf("Sorted : \n");
	for(i=0;i<8;i++){
		printf("A[%d] : %d\n",i+1,A[i]);
	}
}