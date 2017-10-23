#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define pb push_back

vector<int> vertex[100002];
bool visited[100002];
bool color[100002];
queue<int> neighbors;
int level[100002];
int maxLen = 0;

void dfs(int s, int len){
    for(int i = 0; i < vertex[s].size(); i++){
        if(!visited[vertex[s][i]]){
            visited[vertex[s][i]] = true;

            if(color[vertex[s][i]])
                len++;
            else
                len = 0;

            dfs(vertex[s][i], len);

            if(len > maxLen)
                maxLen = len;

        }
    }
}

void bfs(int s){
    if(color[s])
        level[s] = 1;
    else
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
                if(color[vertex[v][i]])
                    level[vertex[v][i]] = level[v]+1;
                else
                    level[vertex[v][i]] = 0;

                if(level[vertex[v][i]] > maxLen)
                    maxLen = level[vertex[v][i]];
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    for(int i = 1; i <= N; i++){
        cin>>color[i];
    }
    int x;
    for(int i = 1; i < N; i++){
        cin>>x;
        vertex[x].pb(i+1);
        vertex[i+1].pb(x);
    }
    /*for(int i = 1 ; i <= N; i++){
        for(int j = 0; j < vertex[i].size(); j++){
            cout<<vertex[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    dfs(1, 1);
    //bfs(1);
    cout<<maxLen<<"\n";
    return 0;
}
