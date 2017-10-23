#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

stack<int> buff;
int n, a[1000], smallVal[1000], smallInd[1000], largeVal[1000], largeInd[1000];

void FindNxtLarge(){
    memset(smallVal, -1, sizeof smallVal);
    memset(smallInd, -1, sizeof smallInd);
    buff.push(0);
    for(int i = 1; i < n; i++){
        int x = buff.top();
        if(a[i] > a[x]){
            while(!buff.empty()){
                x = buff.top();
                largeVal[x] = a[i];
                largeInd[x] = i;
                buff.pop();
                if(!buff.empty()){
                    if(a[buff.top()] > a[i])
                        break;
                }
            }
        }
        buff.push(i);
    }
}

void FindNxtSmall(){
    memset(largeVal, -1, sizeof largeVal);
    memset(largeInd, -1, sizeof largeInd);
    buff.push(0);
    for(int i = 1; i < n; i++){
        int x = buff.top();
        if(a[i] < a[x]){
            while(!buff.empty()){
                x = buff.top();
                smallVal[x] = a[i];
                smallInd[x] = i;
                buff.pop();
                if(!buff.empty()){
                    if(a[buff.top()] < a[i])
                        break;
                }
            }
        }
        buff.push(i);
    }
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    FindNxtSmall();
    FindNxtLarge();
    for(int i = 0; i < n; i++){
        cout<<smallVal[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < n; i++){
        cout<<smallInd[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < n; i++){
        cout<<largeVal[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < n; i++){
        cout<<largeInd[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
