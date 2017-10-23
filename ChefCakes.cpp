#include<stdio.h>
#include<cstdlib>

struct robot{
    int index;
    bool cake;

    robot(){
        index = 0;
        cake = 0;
    }
};

int main(){
    int T;
    long long int M, N, i = 0;
    scanf("%d", &T);
    while(T--){
       scanf("%lld", &N);
       scanf("%lld", &M);
       robot *r;
       r = (robot*)malloc(1000000000 * sizeof(robot));
       for(i = 1; i <= N; i++){
          if((i+M) != N){
             r[i].index = (i+M)%N;
          }
          else{
             r[i].index = i+M;
          }
       }

       /*for(int i = 1; i <= N; i++){
          printf("%d ", r[i].index);
       }*/

       r[1].cake = 1;
       long long int ccount = 1;
       long long int i = r[1].index;
       while(1){
          if(r[i].cake == 0){
             r[i].cake == 1;
             ccount++;
             i = r[i].index;
          }
          else
             break;
       }
       if(ccount == N)
          printf("Yes\n");
       else
          printf("No %lld\n", ccount);

       delete[] r;

    }
    return 0;
}
