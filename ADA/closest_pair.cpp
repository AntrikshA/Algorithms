/*
Closest points among a set of points in the plane
*/

#include "iostream"
#include "fstream"
#include "sstream"
#include "cstring"
#include "cstdlib"
#include "cmath"

using namespace std;

#define NUM 4

int in[100];
int Px[100], Py[100];

double euclidean_dist(int x1, int y1, int x2, int y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

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
}

double minimum(int p[2], int q[2]){

	a = euclidean_dist(Px[p[0]],Py[p[0]],Px[p[1]],Px[p[1]]);
	b = euclidean_dist(Px[q[0]],Py[q[0]],Px[q[1]],Px[q[1]]);

	if(a<b)
		return p;
	else
		return q;
}

int split_pair(int start, int mid, int end, int delta[2]){
	
}

double closest_pair(int start, int end){

	int p[2], q[2], r[2], delta[2];
	if(start<end){
		int mid=(start+end)/2
		p = closest_pair(start,mid);
		q = closest_pair(mid+1,end);
		delta = minimum(p,q);
		r = split_pair(start,mid,end, delta);
		return minimum(delta,r);
	}	
}

int main(){

	cout<<"Need to find the closest pair in a 2D plane ?\n\n";
	cout<<"Enter the x-y coordinates of points";

	for (int i = 0; i < NUM; i++){
		cout<<" x-";
		cin>>Px[i];
		cout<<" y-";
		cin>>Py[i];
	}

	in = Px;
	merge_sort(0, NUM-1);
	Px = in;

	in = Py;
	merge_sort(0, NUM-1);
	Py = in;

	closest_pair(0, NUM-1);

}