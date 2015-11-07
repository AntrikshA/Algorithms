#include <iostream>

using namespace std;

long total_paths = 0;
int n,m;

void solveQuestion(int A[2500][2500], int i, int j, int partial_prod)
{
    if (A[i][j] != 0){
        partial_prod = (A[i][j]*partial_prod)%1000000007;
        if(i==n-1 && j==m-1)
        {
            total_paths = (partial_prod+total_paths)%1000000007;
        }
        else
        {
            for(int k=0; k<(m>n?m:n); k++)
            {
                if(i+k<n)
                    solveQuestion(A,i+k,j,partial_prod);
                if(j+k<m)
                    solveQuestion(A,i,j+k,partial_prod);
                if(i+k<n && j+k<m)
                    solveQuestion(A,i+k,j+k,partial_prod);
            }
        }
    }
}
int main() {
    int A[2500][2500];
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>A[i][j];
        }
    }
    solveQuestion(A,0,0,1);
    cout<<total_paths;
    return 0;
}