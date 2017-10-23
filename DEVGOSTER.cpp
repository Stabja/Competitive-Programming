#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int ll;
using namespace std;
ll fun(int i , char *a , string tem , int K  , int A , int len){   // K = haming dis  A = alphabet size
    if(i == len ){
        //cout<<tem<<"\n";
        return 1;
    }
    ll c = 0;
    int  d = ((i)/2);
    bool f = 0;
    if(K >= 1){
        for(char j  = 'a' ; j < (char)((int)'a'+ A) ; j++){
            tem.push_back(j);
            for(int k = 1 ; k <= d ; k++){
                if( tem[i] == tem[i-k] && tem[i-k] == tem[i-2*k] ){
                    f = 1;
                    break;
                }
            }
            if(!f){
                if(a[i] != tem[i])
                    c = (c%MOD + fun(i+1 , a , tem , K-1 , A , len)%MOD)%MOD;
                else
                    c = (c%MOD + fun(i+1 , a , tem , K , A , len)%MOD)%MOD;
            }
            f = 0;
            tem.erase(tem.begin()+(tem.size()-1));
        }
    }
    else{
        tem.push_back(a[i]);
        //cout<<tem<<"\n";
        for(int k = 1 ; k <= d ; k++){
            if( tem[i] == tem[i-k] && tem[i-k] == tem[i-2*k] ) {
                f = 1;
                break;
            }
        }
        if(!f)
            c = (c%MOD + fun(i+1, a , tem , K , A ,len)%MOD)%MOD;
    }
    return c;
}
int main(){
    int T;
    scanf("%d" , &T);
    while(T--){
        int A , K , len ;
        char str[54] ;
        string tem;
        scanf("%d%d" , &A , &K);
        scanf("%s"  , &str);
        len = strlen(str);
        ll ans = fun(0 , str, tem, K, A, len);
        printf("%lld\n" , ans);
    }
    return 0;
}
