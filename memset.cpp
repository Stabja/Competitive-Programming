#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
    int arr[10];
    arr[0] = 32;
    arr[1] = 16;
    arr[2] = 8;
    arr[3] = 64;
    arr[4] = 21;
    arr[5] = 56;
    cout<<sizeof(arr);
    cout<<"\nBefore memset \n";
    for(int i = 0; i < 6; i++){
        cout<<arr[i]<<" ";
    }
    memset(arr, 0, 9);
    cout<<"\nAfter memset \n";
    for(int i = 0; i < 6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
