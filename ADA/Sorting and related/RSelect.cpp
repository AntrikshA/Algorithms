// Randomised Selection

#include "iostream"
#include "fstream"
#include "sstream"
#include "cstring"
#include "cstdlib"

using namespace std;

#define INPUT_FILE "QuickSort.txt"

int SIZE, array[10000];
long int comparisons=0;

int median(int a, int b, int c){
	if ((a >= b && a <= c) || (a >= c && a <= b)) return a;
	else if ((b >= a && b <= c) || (b >= c && b <= a)) return b;
	else return c;
}

int partition(int start, int end){
	int mid = (start+end)/2 ;
	int m = median(array[start], array[mid], array[end]);
	int temp;
	for(int j=(start+1);j<=end;j++){
		if(array[j]==m){
			temp = array[start];
			array[start] = array[j];
			array[j] = temp;
			break;
		}
	}

	int p = array[start];
	// int temp;
	int i = start+1;
	for(int j=(start+1);j<=end;j++){
		if(array[j]<p){
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	temp = array[i-1];
	array[i-1] = array[start];
	array[start] = temp;
	return i-1;
}

int Rselect(int start, int end, int index){
	// int p;
	if(start<end){
		comparisons += (end-start);
		int p = partition(start,end);
		if(index==p){
			return array[p];
		}
		else if(index<p){
			return Rselect(start,p-1, index);
		}
		else{
			return Rselect(p+1,end, index);
		}
	}
}

int main(){
	ifstream in(INPUT_FILE);

	string line;
	SIZE=0;
	while(getline(in,line)){
		array[SIZE] = atoi(line.c_str());
		SIZE++;
	}

	cout << "Random Select Output : " << Rselect(0,SIZE-1, 9967);
}