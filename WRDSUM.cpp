#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAX 10000

bool num[MAX];
int fac[MAX];
int cnt[MAX];

void sieve(int N){
    for(int i = 2; i <= N; i++){
        //if(!num[i])
        for(int j = i*2; j <= N; j += i){
            num[j] = true;
            fac[j]++;
        }
    }
}

void sieveFactors(){
    for(int i = 2; i <= MAX; i++)
    {
        if(cnt[i] != 0)
            continue;
        for(int j = i; j <= MAX; j += i )
        {
            int k = j;
            while(k%i==0){
                cnt[j]++;
                k /= i;
            }
        }
    }
}

int main(){
    sieveFactors();
    /*for(int i = 0; i < 100; i++){
        if(!num[i])
            cout<<i<<" ";
    }*/
    for(int i = 1; i < 30; i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(int i = 1; i < 30; i++){
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
