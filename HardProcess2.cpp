#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000000
#define LL long long int
#define pb push_back
#define mp make_pair

int arr[300005];

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    if(n == 1 && k == 0){
        if(arr[0] == 0)
            cout<<0<<"\n"<<0;
        else
            cout<<1<<"\n"<<1;
    }
    else if(n == 1 && k == 1){
            cout<<1<<"\n"<<1;
    }
    else{
        int strt = 0;
        int endd = 0;
        int num0 = 0;
        int num1 = 0;
        int maxNum1 = 0;
        int maxStrt = 0;
        int maxEnd = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0)
                num0++;
            else if(arr[i] == 1)
                num1++;
            if(num0 > k){
                endd = i;
                break;
            }
        }
        while(endd < n-1){
            for(int i = strt; i < n; i++){
                if(num0 == k){
                    strt = i;
                    break;
                }
                if(arr[i] == 1)
                    num1--;
                else if(arr[i] == 0)
                    num0--;
            }
            for(int i = endd+1; i < n; i++){
                if(arr[i] == 1)
                    num1++;
                else if(arr[i] == 0)
                    num0++;
                if(num0 > k){
                    endd = i;
                    break;
                }
                if(i == n-1){
                    endd == n-1;
                }
            }
            if(num1 > maxNum1){
                maxNum1 = num1;
                maxStrt = strt;
                maxEnd = endd;
            }
            if(endd == n-1){
                break;
            }
        }
        cout<<maxNum1+k<<" "<<maxStrt<<" "<<maxEnd<<"\n";
    }
    return 0;
}
