#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAXX 1000000000
#define LL long long int
#define pb push_back
#define mp make_pair

int arr[300005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    if(n == 1 && k == 0){
        if(arr[0] == 1)
            cout<<1<<"\n"<<1;
        else
            cout<<0<<"\n"<<0;
    }
    else if(n == 1 && k == 1){
            cout<<1<<"\n"<<1;
    }
    else{
        int strt = 0;
        int endd = 0;
        int num0 = 0;
        int num1 = 0;
        int maxNum0 = 0;
        int maxNum1 = 0;
        int maxStrt = 0;
        int maxEnd = 0;
        for(int i = endd; i < n; i++){
            strt = i;
            for(int j = i; j < n; j++){
                if(arr[j] == 0){
                    num0++;
                }
                else if(arr[j] == 1){
                    num1++;
                }
                if(num0 > k || j == n-1){
                    endd = j-1;
                    break;
                }
            }
            if(num1 > maxNum1){
                maxNum1 = num1;
                maxStrt = strt;
                maxEnd = endd;
            }
            num1 = 0;
            num0 = 0;
        }
        cout<<maxNum1+k<<"\n";
        for(int i = 0; i < n; i++){
            if(i < maxStrt || i > maxEnd)
                cout<<arr[i]<<" ";
            else
                cout<<1<<" ";
        }
    }
    return 0;
}
