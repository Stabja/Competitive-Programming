#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXX 1000001

bool primes[1000001];
ll factors[1000001];
int arr[20];

void sieve(){
    for(int i = 2; i*i <= MAXX; i++){
        if(!primes[i]){
            for(int j = 2*i; j <= MAXX; j+=i){
                primes[j] = true;
            }
        }
    }
    for(int i = 2; i <= MAXX; i++){
        if(!primes[i]){
            for(int j = i; j <= MAXX; j+=i){
                int k = j;
                while(k%i == 0){
                    factors[j]++;
                    k /= i;
                }
            }
        }
    }
}

void PowerSet(int arr[], int N)
{
    int total = pow(2, N);
    ll pleasing = 0;
    for(int i = 0; i < total; i++)
    {
        ll sum = 0;
        for(int j = 0; j < N; j++)
        {
            if(i&(1<<j))
                sum += factors[arr[j]];
        }
        if(sum%2 == 0)
            pleasing += sum;
    }
    printf("%lld", pleasing);
}

void display(){
    for(int i = 2; i <= MAXX; i++){
        cout<<factors[i]<<" ";
    }
}

int main()
{
    sieve();
    for(int i = 1; i <= MAXX; i++){
        factors[i] = factors[i] + factors[i-1];
    }
    int N;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    PowerSet(arr, N);
    return 0;
}
