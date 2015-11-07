#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    long int N;
    char A[200000];

    cin>>N>>q;

    for(int i=0;i<N;i++)
    	cin>>A[i];

    for(int i=0;i<N;i++)
    	cout<<A[i];

    while(q){
    	int x, k, type;

    	cin >> x >> k >> type;
    	cout << x << " " << k << " " << type << endl;
    	q--;
    }
    return 0;
}