#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct comparator{
    bool operator()(int i, int j){
        return i >= j;
    }
};

priority_queue<int, vector<int>, comparator> pq;

void display(){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    int f;
    for(int i = 0; i < n; i++){
        cin>>f;
        pq.push(f);
    }
    int times = 0;
    int flag = 0;
    while(pq.top() < k){
        int x = pq.top();
        pq.pop();
        if(pq.empty()){
            flag = 1;
            break;
        }
        int y = pq.top();
        pq.pop();
        int s = x+2*y;
        if(pq.empty()){
            flag = 1;
            break;
        }
        pq.push(s);
        times++;
    }
    if(flag == 1)
        cout<<-1;
    else
        cout<<times;
    return 0;
}
