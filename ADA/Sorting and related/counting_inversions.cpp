/*
Programming Assignment 1 : Algorithms - Design and Analysis 1
*/

#include "iostream"
#include "fstream"
#include "sstream"
#include "cstring"
#include "cstdlib"

using namespace std;

// #define SIZE 100000
#define INPUT_FILE "IntegerArray.txt"
#define TEST "testing.txt"

long long int SIZE;
long long int array[100000];

long long int count_split(long long int start, long long int mid, long long int end){
	long long int m,n,i,j,k;
	long long int count=0;
	
	m = mid-start+1;
	n = end-mid;

	int a[m], b[n];

	for(i=0;i<m;i++){
		a[i]=array[start+i];
	}
	for(j=0;j<n;j++){
		b[j]=array[j+mid+1];
	}

	i=0;j=0;k=start;
	while(i<m && j<n){
		if(a[i] <= b[j]){
			array[k]=a[i];
			i++;
			k++;
		}
		else if(b[j] <= a[i]){
			array[k]=b[j];
			j++;
			k++;
			count+=(m-i);
		}
	}

	while(i<m){
        array[k] = a[i];
        i++;
        k++;
    } 
    while(j<n){
        array[k] = b[j];
        j++;
        k++;
    }
    return count;
}

long long int count(long long int start, long long int end){
	long long int mid;
	long long int x=0, y=0, z=0;
	if(start==end){
		return 0;
	}
	else{
		mid = (start+end)/2;
		x = count(start, mid);
		y = count(mid+1, end);
		z = count_split(start, mid, end);
	}
	cout<<x+y+z<<endl;
	return x+y+z;
}

int main(){
	ifstream in(INPUT_FILE);

	string line;
	SIZE=0;
	while(getline(in,line)){
		array[SIZE] = atoi(line.c_str());
		// cout<<(array[SIZE])<<endl;
		SIZE++;
	}

	cout<<count(0,SIZE-1)<<" - "<<SIZE<<"";
}