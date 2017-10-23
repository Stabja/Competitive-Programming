#include<bits/stdc++.h>
using namespace std;

map<int, bool> online;

void display(){
    map<int, bool>::iterator it;
    for(it = online.begin(); it != online.end(); ++it){
        cout<<(*it).first<<" ";
    }
    cout<<"\n";
}

int main(){
    int arr[] = {950, 300, 560, 740, 230, 440};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        online[arr[i]] = true;
    }
    int q;
    cin>>q;
    display();
    while(q--){
        /*map<int, bool>::iterator it;
        it = online.begin();
        online.erase(it);
        display();*/
        int val;
        cin>>val;
        map<int, bool>::iterator it = online.find(val);
        if(it != online.end())
            online.erase(it);
        else
            cout<<"NO\n";
        display();
    }
    return 0;
}
