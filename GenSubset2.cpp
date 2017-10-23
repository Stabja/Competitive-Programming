#include<bits/stdc++.h>
#include<stdio.h>
#include<cmath>
using namespace std;

int n;
int arr[20];
long long int facts[20];
int factlen[20];

int primeFactors(int n)
{
    int cnt = 0;
    while (n%2 == 0){
        printf("%d ", 2);
        n = n/2;
        cnt++;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            printf("%d ", i);
            n = n/i;
            cnt++;
        }
    }
    if (n > 2){
        cout<<n;
        cnt++;
    }
    return cnt;
}

int factorial(int n)
{
    if(n == 1)
        return 1;
    else
       return n*factorial(n-1);
}

void PrintSubsets(int N)
{
   int tmp;
   int x = 0;
   int currentSubset = pow(2,N);
   int sum = 0;
   while(x != currentSubset)
   {
      tmp = x;
      int p = 0;
      for(int i = 0; i<N; i++)
      {
         if (tmp & 1){
            cout<<facts[i]<<" ";
            p += factlen[i];
         }
         tmp >>= 1;
      }
      if(p%2 == 0){
          sum += p;
      }
      cout<<"\n";
      x++;
   }
   cout<<sum;
}

int main(){
    //
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        facts[i] = factorial(arr[i]);
        factlen[i] = primeFactors(facts[i]);
    }
    PrintSubsets(n);
    return 0;
}
