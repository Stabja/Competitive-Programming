#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool mark[1000001];

long long PowerSet(long long *set, long long set_size)
{
    long long ans = 0,temp = 0;
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    for(counter = 0; counter < pow_set_size; counter++)
    {
        temp = 0;
        for(j = 0; j < set_size; j++)
        {
            if(counter & (1<<j))
                temp+=set[j];
        }
        if(temp%2 == 0)
            ans+=temp;
       //printf("\n");
    }
    return ans;
}

void sieve(){
    int i,j;
    for(i = 2;i<=1000000;i++){
        if(!mark[i]){
            j = 2;
            while(j*i<=1000000){
                mark[i*j] = true;
                j++;
            }
        }
    }
}

int main() {
    long long ans = 0,j,n,i,k,temp;
    sieve();
    cin>>n;
    long long arr[n],fl[n];
    for(i = 0;i<n;i++){
        cin>>arr[i];
        fl[i] = 0;
    }
    for(i = 0;i<n;i++){
        for(j = 2;j<=arr[i];j++){
            if(!mark[j]){
                k = 1;
                temp = arr[i]/pow(j,k);
                while(temp!=0){
                    fl[i]+=temp;
                    k++;
                    temp = arr[i]/pow(j,k);
                }
            }
        }
    }
    for(i = 0;i<n;i++){
        for(j = i+1;j<n;j++){
            temp+=fl[j];
            if(temp%2 == 0)
                ans+=temp;
        }
    }
    ans = PowerSet(fl,n);
    cout<<ans;
    return 0;
}

