#include <iostream>
#include <math.h>
using namespace std;

int prime_ascii[] = {67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

int prime(int a){
    if(a%2==0)
        return 0;
    for (int i=pow(a,0.5);i>2;i-=1){
        if (a%i==0){
            return 0;
        }
    }
    return 1;
}

int closest(int a){
    int close=prime_ascii[0], diff=99;
    for(int i=0;i<12;i++){
        if(abs(a-prime_ascii[i])<diff){
            diff = a-prime_ascii[i];
            // cout << diff << endl;
            close = prime_ascii[i];
        }
    }
    return close;
}

int main()
{
    int t, n;
    cin >> t;
    while (t>0){
        cin >> n;
        int k = n;
        char string[n+1];
        cin >> string;
        while(n>0){
            if(!prime(int(string[k-n]))){
                // cout << int(string[k-n]);
                cout<<char(closest(int(string[k-n])));
            }
            else{
                cout << string[k-n];
            }
            n--;
        }
        t--;
    }
    return 0;
}
