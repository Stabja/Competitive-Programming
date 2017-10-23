#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

int arr[10000];

int binsearch(int a, int b, int k){
    int mid = (a+b)/2;
    if(mid == 0){
        if(k <= arr[0])
            return mid;
        else
            return mid+1;
    }
    if(k >= arr[mid-1] && k <= arr[mid]){
        if(k == arr[mid-1])
            return mid-1;
        else
            return mid;
    }
    else if(k < arr[mid] && k < arr[mid-1]){
        binsearch(a, mid-1, k);
    }
    else if(k > arr[mid]){
        binsearch(mid+1, b, k);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        int z;
        cin>>z;
        int x = binsearch(0, n, z);
        cout<<x<<"\n";
    }
    return 0;
}
