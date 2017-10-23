#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int i, int j){
    return (i < j);
}

int main(){
    int n, arr[200], lSum = 0, rSum = 0;
    vector<int> left;
    vector<int> right;
    cin>>n;
    for(int i = 0; i < 200; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr, arr + n, compare);
    left.push_back(arr[0]);
    right.push_back(arr[1]);
    lSum = arr[0];
    rSum = arr[1];
    for(int i = 2; i < n; i+=2){
        if(lSum < rSum){
            left.push_back(max(arr[i], arr[i+1]));
            right.push_back(min(arr[i], arr[i+1]));
            lSum += max(arr[i], arr[i+1]);
            rSum += min(arr[i], arr[i+1]);
        }
        else{
            left.push_back(min(arr[i], arr[i+1]));
            right.push_back(max(arr[i], arr[i+1]));
            lSum += min(arr[i], arr[i+1]);
            rSum += max(arr[i], arr[i+1]);
        }
    }
    for(int i = 0; i < left.size(); i++){
        cout<<left.at(i)<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < right.size(); i++){
        cout<<right.at(i)<<" ";
    }
    cout<<"\n";
    cout<<lSum<<" "<<rSum;
    //Adjustments between the arrays
    return 0;
}
