// Longest consecutive path from given starting character.

#include "iostream"

using namespace std;

char mat[3][3] = { {'a', 'c', 'd'}, {'h', 'b', 'e'}, {'i', 'g', 'f'}};
char start = 'e';


int path(){
	
}

int main(){

	for (int i = 0; i<3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << start;

}