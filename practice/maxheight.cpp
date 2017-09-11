#include <iostream>
#include <vector>

using namespace std;

// You have a stack of n boxes, with widths w., heights l\ and depths dr The boxes
// cannot be rotated and can only be stacked on top of one another if each box in the
// stack is strictly larger than the box above it in width, height, and depth. Implement
// a method to build the tallest stack possible, where the heigh t of a stack is the sum of
// the heights of each box.

struct box{
	int width;
	int height;
	int depth;
};

struct box* newBox(int w, int h, int d){
	struct box* box = (struct box*)malloc(sizeof(struct box));
	box->width = w;
	box->height = h;
	box->depth = d;
	return box;
}

int maxheight(int array[], int n){
	
	int Stack[n+1]; // = Max height on placing n-1 boxes above the nth box
	//Base
	Stack[0] = 0;

	//Step
	for(int i=n;i>=0;i--){
		Stack[i] = array[i];
		for(int j=n;j>i;j--){
			if(array[i] < array[j]){
				// cout << array[i] << " " << array[j] << endl;
				Stack[i] = max(Stack[j] + array[i], Stack[i]);
			}
		}
	}

	return Stack[0];
}

int main(){
	int array[] = {0, 1, 2, 3, 4};

	vector<box> list;

	cout << maxheight(array, 4) << endl;

	return 0;
}