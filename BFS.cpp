#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

vector<int> vertex[1000];
queue<int> neighbors;
bool visited[1000];
int level[1000];      //Distance of each vertex from source vertex

int bfs(int s){
    level[s] = 0;
    neighbors.push(s);
    visited[s] = true;
    while(!neighbors.empty()){
        int v = neighbors.front();
        neighbors.pop();
        for(int i = 0; i < vertex[v].size(); i++){
            if(!visited[vertex[v][i]]){
                visited[vertex[v][i]] = true;
                neighbors.push(vertex[v][i]);
                level[vertex[v][i]] = level[v]+1;
            }
        }
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
    for(int i = 1; i <= numVer; i++){
        cout<<level[i]<<" ";
    }
    return 0;
}
