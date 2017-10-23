#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

vector<int> vertex[1000];
stack<int> maxFlowPath;
queue<int> neighbors;
bool visited[1000];
int level[1000];      //Distance of each vertex from source vertex
int path[1000];

int bfs(int s){
    path[s] = 0;
    level[s] = 0;
    neighbors.push(s);
    visited[s] = true;
    while(!neighbors.empty()){
        int v = neighbors.front();
        neighbors.pop();
        for(int i = 0; i < vertex[v].size(); i++){
            int w = vertex[v][i];
            if(!visited[w]){
                visited[w] = true;
                path[w] = v;
                neighbors.push(w);
                level[w] = level[v]+1;
            }
        }
    }
}

void calculatePath(int dest){
    int i = dest;
    maxFlowPath.push(dest);
    while(i != 1){
        i = path[i];
        maxFlowPath.push(i);
    }
}

void printPath(int n){
    for(int i = 1; i <= n; i++){
        cout<<path[i]<<" ";
    }
}

int main(){
    int numVer, numEdg, sum = 0;
    cin>>numVer>>numEdg;
    for(int i = 0; i < numEdg; i++){
        int x, y;
        cin>>x>>y;
        vertex[x].push_back(y);
        vertex[y].push_back(x);
    }
    bfs(1);
    /*for(int i = 1; i <= numVer; i++){
        cout<<level[i]<<" ";
    }
    cout<<"\n";*/
    printPath(numVer);
    int p;
    cout<<"\nHowMany - ";
    cin>>p;
    while(p--){
        int des;
        cout<<"\nWhich destination - ";
        cin>>des;
        calculatePath(des);
        while(!maxFlowPath.empty()){
            cout<<maxFlowPath.top()<<" ";
            maxFlowPath.pop();
        }
    }
    return 0;
}
