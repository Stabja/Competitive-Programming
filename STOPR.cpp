#include<bits/stdc++.h>
#include<algorithm>

#define MAXX 1000000007

long long int polySeq[100002];

long long int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}

long long int findMMI(long long int n,long long int M)
{
    return fast_pow(n,M-2,M);
}

void genSequence(long long int M, long long int x){
    memset(polySeq, 0, sizeof polySeq);
    polySeq[0] = 1;
    if(M == 3){
        for(int i = 1; i < x; i++){
            polySeq[i] = polySeq[i-1] + i+1;
        }
    }
    else{
        polySeq[1] = M%MAXX;
        for(int i = 2; i < x; i++){
            long long int i1 = findMMI(i, MAXX);
            polySeq[i] = (polySeq[i-1]%MAXX*((i+M-1)%MAXX*i1%MAXX)%MAXX)%MAXX;
            //polySeq[i] = polySeq[i-1]*(i+M-1)/i;
        }
    }
    /*else{
        for(int i = 1; i < x; i++){
            polySeq[i] = polySeq[i-1] + (M-1)*i;
        }
    }*/
}

int main(){
    int T, N, x;
    long long int M, arr[100005];
    /*for(int i = 1; i < 50; i++)
        cout<<facto[i]<<" ";*/
    scanf("%d", &T);
    while(T--){
        long long int sum = 0;
        scanf("%d%d%lld", &N, &x, &M);
        if(M <= 2){
            for(int i = 0; i < N; i++){
                scanf("%lld", &arr[i]);
            }
            while(M--){
                for(int i = 1; i < x; i++){
                    arr[i] = (arr[i]%MAXX + arr[i-1]%MAXX)%MAXX;
                }
            }
            printf("%lld\n", arr[x-1]%MAXX);
        }
        else{
            genSequence(M, x);
            /*for(int i = 0; i < N; i++){
                printf("%lld ", polySeq[i]);
            }*/
            for(int i = 0; i < N; i++){
                scanf("%lld", &arr[i]);
            }
            for(int i = 0; i < x; i++){
                sum = (sum%MAXX + (arr[i]%MAXX*polySeq[x-i-1]%MAXX)%MAXX)%MAXX;
            }
            printf("%lld\n", sum%MAXX);
            sum = 0;
        }
    }
    return 0;
}
