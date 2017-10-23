#include<bits/stdc++.h>
using namespace std;

queue<int> stak;

int main(){
    stak.push(2);
    stak.push(7);
    stak.push(3);
    stak.push(8);
    stak.push(5);
    while(!stak.empty()){
        cout<<stak.front()<<"\n";
        stak.pop();
    }
    return 0;
}
