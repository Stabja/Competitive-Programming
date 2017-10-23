#include<bits/stdc++.h>
using namespace std;

list<int> plist;

void display(){
    for(list<int>::iterator it = plist.begin(); it != plist.end(); ++it){
        cout<<(*it)<<" ";
    }
    cout<<"\n";
}

int main(){
    for(int i = 1; i <= 10; i++){
        plist.push_back(i*3);
    }
    display();
    plist.pop_front();
    display();
    plist.pop_back();
    display();
    list<int>::iterator it = plist.end();
    --it;
    int val = (*it)*(*--it);
    cout<<val;
    return 0;
}
