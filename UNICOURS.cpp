#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define LL long long int
#define mp make_pair
#define pb push_back

int arr[100005];
bool b[100005];

int main(){
    int n;
    cin>>n;
    int prod = 1;
    for(int i = 0; i <= n; i++){
        if(arr[i] > 1){
            prod *= arr[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
