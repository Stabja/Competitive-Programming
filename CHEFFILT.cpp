#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

string image, dummy, filter[10002];

void ApplyFilter(string str2){
    for(int i = 0; i <10; i++){
        if(dummy[i] == 'w' && str2[i] == '+')
            dummy[i] = 'b';
        else if(dummy[i] == 'w' && str2[i] == '-')
            dummy[i] = 'w';
        else if(dummy[i] == 'b' && str2[i] == '+')
            dummy[i] = 'w';
        else if(dummy[i] == 'b' && str2[i] == '-')
            dummy[i] = 'b';
    }
}

void PrintSubsets(int N)
{
   int currentSubset = pow(2,N);
   int tmp;
   int x = 0;
   int coun = 0;
   string output;
   while(x != currentSubset)
   {
      dummy = image;
      tmp = x;
      for(int i = 0; i < N; i++)    //Apply all filters
      {
         if (tmp & 1){
            ApplyFilter(filter[i]);
         }
         tmp >>= 1;
      }
      for(int i = 0; i < 10; i++){  //Convert to number
          if(dummy[i] == 'w')
             output[i] = '1';
          else if(dummy[i] == 'b')
             output[i] = '0';
      }
      int val = atoi(output.c_str());
      if(val == 0){
          coun++;
      }
      x++;
   }
   cout<<coun<<"\n";
}



int main(){

    int T, N;
    cin>>T;
    while(T--){
        cin>>image;
        cin>>N;
        for(int i = 0; i < N; i++){
            cin>>filter[i];
        }
        PrintSubsets(N);
    }
    return 0;
}
