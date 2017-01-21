#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int kmin(ull x, ull start, ull end){
	ull mid;
	if(start<end){
		// cout << arr[start] << " " << arr[end] << endl;
		while(start<=end){
			mid = (ull)(start+end)/2;
			if(mid==x){
				return mid;
			}
			else if(mid>x){
				end = mid-1;
			}
			else if(mid<x){
				start = mid+1;
			}
		}
	}
	else{
		// cout << "else";
		int n=end;
		while(start<=end){
			mid = (ll)(start+end)/2;
			if(mid==x){
				return n-mid+1;
			}
			else if(mid<x){
				end = mid-1;
			}
			else if(mid>x){
				start = mid+1;
			}
			// cout << start << " " << end <<  endl;
		}
	}
	return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int i=0;
        ull start[n], end[n];
        while(n--){
            cin >> start[i] >> end[i];
            i++;
        }
        while(q--){
            ull x;
            cin >> x;
            for(int j=0;j<i;j++){
                cout << kmin(x,start[j],end[j]) << endl;
            }
        }
    }
    return 0;
}
