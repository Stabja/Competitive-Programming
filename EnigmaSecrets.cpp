#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> vertex[1000002];
queue<int> neighbors;
bool visited[1000002];
int level[1000];
int arr[1000002];

void bfs(int s){
    //level[s] = 0;
    neighbors.push(s);
    visited[s] = true;
    while(!neighbors.empty()){
        int v = neighbors.front();
        neighbors.pop();
        for(int i = 0; i < vertex[v].size(); i++){
            if(!visited[vertex[v][i]]){
                visited[vertex[v][i]] = true;
                neighbors.push(vertex[v][i]);
                //level[vertex[v][i]] = level[v]+1;
            }
        }
    }
}

void dfs(int s){
    //cout<<s<<" ";
    int sum = 0;
    visited[s] = true;
    for(int i = 0; i < vertex[s].size(); i++){
        if(!visited[vertex[s][i]]){
            visited[vertex[s][i]] = true;
            dfs(vertex[s][i]);
        }
    }
}

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(){
    int N, X;
    cin>>N>>X;
    int e;
    for(int i = 1; i <= N; i++){
        cin>>e;
        vertex[e].push_back(i);
        vertex[i].push_back(e);
    }
    int money = 0;
    for(int i = 1; i <= N; i++){
        //cout<<freq[i].first<<" "<<freq[i].second<<"\n";
        if(!visited[i]){
            dfs(i);
            money += X;
        }
    }
    cout<<money;
    return 0;
}
