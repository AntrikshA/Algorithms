#include <stdio.h>
#include <stdlib.h>

int in[100];

int merge_sort(int s, int e){
	int c;
	if(s<e){
		c = (s+e)/2;
		merge_sort(s,c);
		merge_sort(c+1,e);
		merge(s,c,e);
	}
}

int merge(int s,int c, int e){
	int m,n,i,j,k;
	int a[100], b[100];
	
	m = c-s+1;
	n = e-c;

	for(i=0;i<m;i++){
		a[i]=in[s+i];
	}
	for(j=0;j<n;j++){
		b[j]=in[j+c+1];
	}

	i=0;j=0;k=s;
	printf("%d %d %d | %d %d | %d-%d %d-%d\n",s,c,e,m,n,s+i,a[i],j+c+1,b[j] );
	while(i<m && j<n){
		if(a[i] <= b[j]){
			in[k]=a[i];
			i++;
			k++;
		}
		else if(b[j] <= a[i]){
			in[k]=b[j];
			j++;
			k++;
		}
	}

	while(i<m){
        in[k] = a[i];
        i++;
        k++;
    } 
    while(j<n){
        in[k] = b[j];
        j++;
        k++;
    }
    for(i=0;i<e;i++){
		printf("%d ",in[i]);
	}
	printf("\n");
}

int main(){
	int n,i;
	
	printf("Enter size (max 100) : \n");
	scanf("%d",&n);
	
	printf("Enter an %d values\n",n );
	for(i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	
	printf("Values received :\n");
	for(i=0;i<n;i++){
		printf("%d\n",in[i]);
	}
	
	printf("Sorting now...\n");
	merge_sort(0,n-1);

	for(i=0;i<n;i++){
		printf("%d\n",in[i]);
	}
}