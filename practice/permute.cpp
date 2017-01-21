#include <iostream>
using namespace std;

// int search(int arr[], int x, int n){
//     for(int i=0;i<n;i++){
//         if(arr[i]==x){
//             return true;
//         }
//     }
//     return false;
// }

int permute(int distinct, int n){
    int visited[n];
    for(int i=0;i<distinct;i++){
        
    }
}

int main()
{
    int n;
    cin >> n;
    int k=n;
    int arr[n], distinct=0;
    while(k--){
        int x;
        cin >> x;
        arr[distinct]=x;
        distinct++;
        // if(not search(arr,x, distinct)){
        //     arr[distinct]=x;
        //     distinct++;
        // }
    }
    cout << permute(distinct, n);
    return 0;
}
