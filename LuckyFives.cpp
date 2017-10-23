#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return x;
}
const int N = 2009;
pair<int,int> a[N];
int arr[N];
int bit[N];
int BIT[N];
int bIt[N];
int n,q,cur=1;

void update(int *b,int i,int val){
    while(i<=n+1){
        b[i]+=val;
        i+=i&-i;
    }
}
int query(int *b,int i){
    int res=0;
    while(i>0){
        res+=b[i];
        i&=i-1;
    }
    return res;
}
int answer[N][N]={0};
int main(){
    n=scan(),q=scan();
    for(int i=1;i<=n;i++){
        a[i].first=scan();
        a[i].second=i;
    }
    a[0].first=-1;
    sort(a+1,a+1+n);
    /*for(int i = 0; i <= n; i ++){
        cout<<a[i].first<<" ";
    }
    cout<<"\n";
    for(int i = 0; i <= n; i++){
        cout<<a[i].second<<" ";
    }*/
    for(int i=1;i<=n;++i){
        if(a[i].first!=a[i-1].first){
            arr[a[i].second]=++cur;
        }
        else{
            arr[a[i].second]=cur;
        }
    }
    cout<<"\n";
    /*for(int i = 0; i <= n; i++){
        cout<<arr[i]<<" ";
    }*/
    int sz  = sizeof(int)*N;
    for(int i = 1; i < n; ++i){
        memset(bit,0,sz);
        memset(BIT,0,sz);
        memset(bIt,0,sz);
        for(int j=i+1;j<=n;++j){
            if(arr[j]<arr[i]){
                update(bit,arr[j],1);
            }
            int res = query(bit,arr[j]-1);
            update(BIT,arr[j],res);
            int temp = query(BIT,n+1)-query(BIT,arr[j]);
            update(bIt,arr[j],temp);
            answer[i][j]=query(bIt,arr[j]-1);
        }
    }
    while(q--){
        int l=scan(),r=scan();
        printf("%d\n",answer[l][r]);
    }
}
