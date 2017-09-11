#include <iostream>

using namespace std;

// Implement 3 stacks with an array

class Stack{
public:
	int array[60];
	int top[3];
	int bottom[3];
	int ratio=60/3;

	Stack(){
		for(int i=0;i<3;i++){
			top[i] = bottom[i] = i*(60/3);
		}
	}

	int push(int stacknum, int value){
		if(stacknum==1 || stacknum==2){
			if(top[stacknum] < (stacknum+1)*ratio ){
				array[top[stacknum]] = value;
			}
			else{

			}
		}
		else if(stacknum==3){

		}
		else{
			cout << "Invalid Stack selected" << endl;
		}
	}

	int pop(int stacknum, int value){
		if(stacknum==1 || stacknum==2 || stacknum==3 ){

		}
		else{
			cout << "Invalid Stack selected" << endl;
		}
	}

}

int main(){
	
}