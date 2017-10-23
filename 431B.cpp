#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int M[6][6];

int main(){
    int arr[] = {0, 1, 2, 3, 4};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin>>M[i][j];
        }
    }
    long long int happ = 0;
    long long int maxHapp = 0;
    do{
        /*for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";*/
        happ = 0;
        for(int i = 0; i < 5; i++){
            for(int j = i; j < 5; j+=2){
                if(j+1 < 5)
                    happ += M[arr[j]][arr[j+1]] + M[arr[j+1]][arr[j]];
            }
        }
        maxHapp = max(happ, maxHapp);
    }while(next_permutation(arr, arr+5));
    cout<<maxHapp;
    return 0;
}
