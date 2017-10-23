#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int val[1000];
bool visited[1000];
vector<int> vertex[1000];

int dfs(int s){
    int sum = 0;
    visited[s] = true;
    for(int i = 0; i < vertex[s].size(); i++){
        if(!visited[vertex[s][i]]){
            visited[vertex[s][i]] = true;
            sum += val[vertex[s][i]] + dfs(vertex[s][i]);
        }
    }
    return sum;
}

int main(){
    int numVer, numEdg, arr[1000], sum = 0;
    cin>>numVer>>numEdg;
    for(int i = 0; i < numEdg; i++){
        int x, y;
        cin>>x>>y;
        vertex[x].push_back(y);
        vertex[y].push_back(x);
    }
    for(int i = 1; i <= numVer; i++){
        cin>>val[i];
    }
    memset(visited, false, numVer);
    for(int i = 1; i <= numVer; i++){
        if(!visited[i]){
            visited[i] = true;
            sum += val[i] + dfs(i);
            cout<<sum<<" ";
            sum = 0;
            //sum = max(sum, val[i] + dfs(i));
        }
    }
    return 0;
}

