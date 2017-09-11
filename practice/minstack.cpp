#include <iostream>

using namespace std;

// Implement 3 stacks with an array

class Stack{
public:
	int array[60];
	int minim[60];
	int top;

	Stack(){
		top = -1;
		minim[top] = 9999;
	}

	int push(int value){
		if(top==59){
			cout << "Stack full" << endl;
			return -1;
		}
		array[++top] = value;
		if(value < minim[top-1]){
			minim[top] = value;
			// cout << minim[top] << " -- ";
		}
		else{
			minim[top] = minim[top-1];
		}
	}

	int pop(){
		return array[top--];
	}

	int minm(){
		return minim[top];
	}

	void print(){
		for(int i=0;i<=top;i++)
			cout << array[i] << endl;
		cout << "top: " << top+1 << endl;
	}

	void printm(){
		for(int i=0;i<=top;i++)
			cout << minim[i] << endl;
		cout << "top: " << top+1 << endl;
	}
};

int main(){
	int array[] = {2, 4, 5, 7, 1, 9, 6, 8, 0, 3, 2, 6};

	Stack stack;
	for(int i=0;i<12;i++){
		stack.push(array[i]);
	}
	stack.print();
	cout << stack.minm() << endl;
	stack.printm();
	return 0;
}