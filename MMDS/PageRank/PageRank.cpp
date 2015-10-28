#include <iostream>
#include <vector>

using namespace std;

#define NODES 20 // will be addressed as 'N' all through the comments

int PageRank(vector< vector<int> > graph){ // Graph adjacency matrix as input: sparse matrix 'N*N'
	vector<double> rank (NODES);
	vector< vector<double> > A(NODES, vector<double>( NODES ) );

	for (unsigned i=0; i<NODES; ++i)	//Each rank initialised with 1/N
		rank[i] = double(1/double(NODES));

	for (unsigned i=0; i<NODES; ++i)	// Google Matrix to reduce error
		for (unsigned j=0; j<NODES; ++j)
			A[i][j] = double(0.15 * double(1/double(NODES))) + double(0.85 * graph[i][j]);

	cout<<"Final Google Matrix : \n";
	for (unsigned i=0; i<NODES; ++i){
		for (unsigned j=0; j<NODES; ++j)
			cout<<" "<<A[i][j];
		cout<<endl;
	}

	while(1){
		int flag = 1;
		vector<double> prevrank = rank;

		for (unsigned i=0; i<NODES; ++i) // Formula for calculating ranks implemented
			for (unsigned j=0; j<NODES; ++j)
				rank[j] += double(A[i][j] * rank[j]);

		/*cout<<"Ranks : ";
		for (unsigned i=0; i<NODES; ++i)
			cout<<rank[i]<<" ";*/

		// checks if the previous rank vector was equal to the new rank vector, if so
		 // our rank vector will not change now
		for (unsigned i=0; i<NODES; ++i){ 
			if(prevrank[i] != rank[i]){
				flag = 0;
				break;
			}
		}

		if(flag==1)
			break;
	}

	cout<<"Ranks : ";
	for (unsigned i=0; i<NODES; ++i)
		cout<<rank[i]<<" ";

}

int main(){

	// initialise the adjacency sparse matrix of N*N
	vector< vector<int> > graph (NODES, vector<int>( NODES ) ); //initialise this to values yourself
	// If you don't initialise the graph matrix, all ranks will be equal to 'inf' 
	PageRank(graph);
}