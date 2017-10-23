#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

list<int> myList;
int arr[100004];


int main(){
    int n;
    cin>>n;
    int x;
    for(int i = 0; i < n; i++){
        cin>>x;
        myList.push_back(x);
    }
    int days = 0;
    int flag = 0;
    do{
    list<int>::iterator it = myList.begin();
    list<int>::iterator it2 = ++it;
    int k = 0;
    list<int>::iterator last = myList.end()--;
    for(it = myList.begin(); it != last; ++it){
        k++;
        if((*it2) >= (*it))
            arr[k] = 1;
        if(it2 != myList.end())
            ++it2;
    }
    k = 0;
    /*for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }*/
    it = myList.begin();
    while(it!=myList.end()){
        if(arr[k] == 1){
            it2 = it;
            ++it;
            k++;
            myList.erase(it2);
        }
        else{
            k++;
            ++it;
        }
    }
    /*for(it = myList.begin(); it != myList.end(); ++it){
        cout<<(*it)<<" ";
    }*/
    flag = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            flag = 1;
            break;
        }
    }
    memset(arr, 0, sizeof arr);
    n = myList.size();
    days++;
}while(flag);
    cout<<days-1;
    return 0;
}
