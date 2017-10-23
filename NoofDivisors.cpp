#include<bits/stdc++.h>
using namespace std;

#define MAXX 100005

bool prime[MAXX];
int primes[MAXX];

void sieve()
{
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=MAXX; p++){
        if (prime[p] == true){
            for (int i=p*2; i<=MAXX; i += p)
                prime[i] = false;
        }
    }
}

void display(){
    for(int p=2; p<=20; p++){
        if(prime[p])
            cout << p << " ";
    }
}

int main(){
    sieve();
    int n;
    cin>>n;
    int k = n;
    int numDiv = 1;
    for(int i = 2; i < MAXX; i++){
        int cnt = 1;
        if(prime[i]){
            while(k%i==0){
                k /= i;
                cnt++;
            }
            numDiv *= cnt;
            if(k == 1)
                break;
        }
    }
    cout<<numDiv;
    return 0;
}
