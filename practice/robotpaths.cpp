#include <iostream>

using namespace std;

// Imagine a robot sitting on the upper left comer of an X by Ygrid. The robot can only
// move in two directions: right and down. How many possible paths are there for the
// robot to go from (0, 0) to (X, Y) ?

int paths(int x, int y){
	if(x==0 || y==0){
		return 1;
	}
	return (paths(x-1, y) + paths(x, y-1));
}

int main(){
	int x=3, y=3;

	cout << paths(x, y) << endl;

	return 0;

}