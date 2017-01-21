#include <iostream>
using namespace std;

int bulbs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    int t, n;
    int digit;
    cin >> t;
    while(t--){
        cin >> n;
        int min=100001, val;
        int k=n;
        while (n--){
            int sum=0;
            cin >> digit;
            int temp = digit;
            if (temp == 0){
                sum = bulbs[0];
            }
            while(temp>0){
                sum += bulbs[temp%10];
                temp = temp/10;
            }
            if(n==k){
                min = sum;
                val = digit;
            }
            if(min > sum){
                min = sum;
                val = digit;
                cout << min << " " << val << endl;
            }
            cout << sum <<" "<<min<< endl;
        }
        cout << val << endl;
    }
    return 0;
}
