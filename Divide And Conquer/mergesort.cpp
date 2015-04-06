#include <iostream>
#include <math.h>
#define N 5
using namespace std;
int *a = new int[10];

int merge(int p, int q, int r){
	cout<<p<<q<<r;
	int n1 = q-p+r; //3
	int n2 = r-q;	//1
	int i,j;
	int l[10];
	int k[10];
	for(i=1;i<=n1;i++){
		l[i-1] = a[p+i-1]; // a[0], a[1], a[2]
	}
	for(i=1;i<=n2;i++){
		k[i-1] = a[q+i]; // a[0]
	}
	l[n1]='\0';
	k[n2]='\0';
	j=0;
	i=0;
	for(int n=p;n<r;n++){ // 0 to 2
		cout<<"|";
		if(l[i] <= k[j] && l[i]!='\0' && k[j]!='\0') {
			a[n] = l[i];
			a[n+1] = k[j];
			i++;
		}
		else if(l[i] >= k[j] && l[i]!='\0' && k[j]!='\0'){
			a[n] = k[j];
			a[n+1] = l[i];
			j++;
		}
		for(int i=0;i<N;i++){
			cout<<a[i];
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

	cout<<"Enter 5 numbers : "<<endl;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	cout<<"Sorting .";

	mergesort(0,N);

	for(int i=0;i<N;i++){
		cout<<endl<<a[i];
	}
	cout<<"\n\t\t-- END --\n\n";
}