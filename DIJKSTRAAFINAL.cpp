#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > vertex[10000];
int d[10000];
int V, E;

void dijkstra(int src){
    fill(d, d + 10000, 100000);
    d[src] = 0;
    int u;
    set<pair<int,int> > s;
    s.insert(make_pair(d[src], src));
    while(!s.empty()){
        u = s.begin() -> second;
        s.erase(s.begin());
        //for(auto p : adj[u]){ //adj[v][i] = pair(vertex, weight)
        for(int i = 0; i < vertex[u].size(); i++){
            int v = vertex[u][i].first;
            int wt = vertex[u][i].second;
            if(d[v] > d[u] + wt){
                s.erase({d[v], v});
                d[v] = d[u] + wt;
                s.insert({d[v], v});
            }
        }
    }
}

int main(){
    cin>>V>>E;
    for(int i = 0; i < 2*E ; i++){
        int u, v, w;
        cin>>u>>v>>w;
        vertex[u].push_back(make_pair(v, w));
    }
    dijkstra(1);
    for(int i = 1; i <= V; i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
