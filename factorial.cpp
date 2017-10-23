#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 100000
int cnt[100009];
int N, arr[20];

void PrintSubsets(int N)
{
   int tmp;
   int x = 0;
   int currentSubset = pow(2,N);
   long long int sum = 0;
   while(x != currentSubset)
   {
      tmp = x;
      long long int p = 0;
      for(int i = 0; i<N; i++)
      {
         if (tmp & 1){
            p += cnt[arr[i]];
         }
         tmp >>= 1;
      }
      if(p%2 == 0){
          sum += p;
      }
      x++;
   }
   cout<<sum;
}

int main(){
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    for(int i = 2; i <= MAX; i++ ){
        if(cnt[i] != 0 )
            continue;
        for(int j = i; j <= MAX; j += i ){
            int k = j;
            while(k%i == 0){
                cnt[j]++;         //cnt[n] stores the sum of prime powers of all nos
                k /= i;
            }
        }
    }
    for(int i = 2; i <= MAX; i++){
        cnt[i] = cnt[i] + cnt[i-1];
    }
    PrintSubsets(N);
    return 0;
}
