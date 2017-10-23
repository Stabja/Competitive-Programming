#include<iostream>
using namespace std;

int BITree[100005];
int coins[100005]

int getSum(int index){
    index++;
    int sum = 0;
    while(index > 0){
        sum += BITree[index];
        index = index - (index & (-index)); //Getting the parent by flipping the rightmost set bit
    }
    return sum;
}

int updateBITree(int n, int index, int val){
    index++;
    while(index <= n){
       BITree[index] += val;
       index = index + (index & (-index));        //Going to the next element
    }
}

void constructBITree(int arr[], int n){
    for(int i = 0; i <= n; i++){
        BITree[i] = 0;
    }
    for(int i = 0; i < n; i++){
        updateBITree(n, i, arr[i]);
    }
}

int main(){
    int n, q;
    cin>>n>>q;
    while(q--){
        int k, a, b;
        cin>>k>>a>>b;
        if(k == 0){
            for(int i = a; i <= b; i++){
                if(coins[i] == 0){
                    coins[i]++;
                    updateBITree()
                }
                else{
                    coins
                }
            }
        }
        else
    }
    return 0;
}
