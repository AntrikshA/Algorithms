#include <iostream>
#include <math.h>
using namespace std;
int *a = new int[10];

int merge(int p, int q, int r){
	int n1 = q-p+r;
	int n2 = r-q;
	int i,j;
	int *l = new int[10];
	int *k = new int[10];
	for(i=0;i<n1;i++){
		l[i] = a[p+i-1];
	}
	for(i=0;i<n2;i++){
		k[i] = a[q+i];
	}
	l[n1+1]=NULL;
	k[n2+1]=NULL;
	j=0;
	i=0;
	for(int n=p; n<=r;n++){
		cout<<".";
		if(l[i] <= k[j] && l[i]!=NULL && k[j]!=NULL) {
			a[n] = l[i];
			i++;
		}
		else if(l[i] >= k[j] && l[i]!=NULL && k[j]!=NULL){
			a[n] = k[j];
			j++;
		}
	}
}

int mergesort(int p,int r){
	if (p<r){
		int q=((p+r)/2);
		cout<<".";
		mergesort(p,q);
		mergesort(q+1,r);
		merge(p,q,r);
	}
}

int main(){
	
	cout<<"\t\t:-: MERGE SORT :-: "<<endl;

	cout<<"Enter 10 numbers : "<<endl;
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	cout<<"Sorting .";

	mergesort(0,10);
	for(int i=0;i<10;i++){
		cout<<endl<<a[i];
	}
	cout<<"\t\t-- END --\n\n";
}