#include <iostream>
#include <math.h>
using namespace std;
#define mod 1000000007

int sinfinity(int P, int a){
    int arr[P];
    int i=0;
    while(P>0){
        int r = P%2; 
        arr[i++] = r;
        P = P/2;
        // cout << r ;
    }
    // cout << endl;
    
    int out = 0;
    int base = 1;
    for(int j=i-1;j>=i-a;j--){
        cout << arr[j];
        out += arr[j]*base;
        base*=2;
    }
    cout << endl;
    cout << "out" << out <<  endl;
    return out;
}

int F(int a, int b){
    if(a%b==0){
        // cout << a << endl;
        return pow(2,a-1);
    }
    return sinfinity(F(b,a%b), a);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << (unsigned long long)F(a,b) << endl;
    }
    return 0;
}
