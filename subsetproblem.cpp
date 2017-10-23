#include<stdio.h>
#include<cmath>

void PrintSubsets(int N, int source[])
{
   //int source[3] = {1,2,3};
   int currentSubset = pow(2,N);
   int tmp;
   int x = 1;
   while(x != currentSubset)
   {
      printf("(");
      tmp = x;
      for(int i = 0; i < N; i++)
      {
         if (tmp & 1)
         printf("%d ", source[i]);
         tmp >>= 1;
      }
      printf(")\n");
      x++;
   }
}

int main(){
    int n, a[100];
    printf("Enter the no of elements");
    scanf("%d", &n);
    printf("Enter the elements");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    PrintSubsets(n, a);
    return 0;
}
