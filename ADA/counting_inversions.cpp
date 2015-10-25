#include "iostream"
#include "fstream"
#include "sstream"
#include "cstring"
#include "cstdlib"

using namespace std;

#define SIZE 100000
#define INPUT_FILE "IntegerArray.txt"

int array[SIZE], x, y, z;

int count(int start, int end){
	int mid;
	if(n==1){
		return 0;
	}
	else{
		mid = (start+end)/2
		x = count(start, mid);
		y = count(mid+1, end);
		z = count_split(start, mid, end);
	}
	return x+y+z;
}

int count_split(int start, int mid, int end){

}

int main(){
	ifstream in(INPUT_FILE);

	string line;
	int i=0;
	while(getline(in,line)){
		array[i] = atoi(line.c_str());
		cout<<array[i]<<endl;
		i++;
	}

	cout<<count(0,SIZE);
}