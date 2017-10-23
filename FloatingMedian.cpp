#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define MOD 65536
#define MAXN 250000

int tree[MOD+2];
int x[MAXN+2];

struct FloatingMedian{

    void update(int dex, int val){
        while(dex <= MOD){
            tree[dex] += val;
            if(dex == 0)
                break;
            dex += (dex & -dex);
        }
    }

    int find(int fre){
        int dex = MOD, t;
        int bitMask = (1<<15);
        while(bitMask !=0 && dex >= 1){
            t = dex - bitMask;
            if(fre <= tree[t])
                dex = t;
            else
                fre -= tree[t];
            bitMask >>= 1;
        }
        return dex;
    }

    long long sumOfMedians(int seed, int mul, int add, int N, int K){
        int mid = (K+1)/2;
        long long sum = 0;
        int i;
        memset(tree,0,sizeof(tree));
        for(i = 0; i < N; i++){
            if(i == 0) x[i] = seed;
            else x[i] =(x[i-1] * (long long)mul + add) % MOD;
            update(x[i]+1,1);
            if(i == K-1)
                sum += (find(mid)-1);
            if(i >= K){
                update(x[i-K]+1, -1);
                sum += (find(mid)-1);
            }
        }
        return sum;
    }

};


int main(){
    FloatingMedian fl;
    cout<<fl.sumOfMedians(3, 1, 1, 10, 3);
    return 0;
}


