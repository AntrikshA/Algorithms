#include <iostream>
using namespace std;
#define N 11
int board[N][N];

void print(int board[][N], int dim){
// 	cout << "YES" << endl;
	for (int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

int is_attacked(int x,int y,int board[][N],int dim){

	for(int i=0;i<dim;i++){ 
		if (board[x][i]==1) // check row
			return true; 
		if (board[i][y]==1)	// check column
			return true;
	}
	
	for (int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(i+j==x+y && board[i][j]==1){ // check right to left diagonal
				return true;
			}
			if(i-j==x-y && board[i][j]==1){ // check left to right diagonal
				return true;
			}
		}
	}
	
	return false; // if all other cases fail.
}

int nqueens(int board[][N], int n, int dim){
	if (n==0){
		return true;
	}
	for (int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if (not is_attacked(i,j,board,dim)){	// if not being attacked
				board[i][j]=1;						// set queen
				if (nqueens(board, n-1, dim)){		// check if this position satisfies other queens
					return true;
				}
				board[i][j]=0;						// if other positions are not compatible -- backtrack.
			}
		}
	}
	return false;									// if nothing went our way
}

int main()
{
	int n;
    cin >> n;
    int dim = n;
    
    for (int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			board[i][j]=0;
		}
	}

    if (nqueens(board, n, dim)){
    	print(board,dim);
    }
    else{
        cout << "Not possible" << endl;
    }
    return 0;
}
