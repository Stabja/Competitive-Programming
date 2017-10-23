#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

char arr[5000];

LL LPS(LL l, LL r){
    if(l > r){
        return 0;
    }
    if(l == r){
        return 1;
    }
    if(arr[l] != arr[r]){
        return max(LPS(l, r-1), LPS(l+1, r));
    }
    else{
        return LPS(l+1, r-1)+2;
    }
}

int main(){
    int n;
    scanf("%s", &arr);
    n = strlen(arr);
    //cout<<n<<"\n";
    LL ans = LPS(0, n-1);
    cout<<ans;
    return 0;
}
