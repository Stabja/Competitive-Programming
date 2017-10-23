#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y;
};

node edges[500007];
int arr[500007];
vector < vector < int > > graph;
bool visited[500007];

int dfs(int src){
    int ans,i;
    ans=0;
    for(i=0;i<graph[src].size();i++){
        if(!visited[graph[src][i]]){
            //cout<<"node"<<' '<<graph[src][i]<<endl;
            visited[graph[src][i]]=true;
            ans=ans+arr[graph[src][i]]+dfs(graph[src][i]);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n, m, i, q, x, y, ans;
    char c;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)cin>>arr[i];
    for(i=1;i<=m;i++){
        cin>>edges[i].x>>edges[i].y;
    }
    while(q--){
        cin>>c;
        if(c=='P'){
            cin>>x>>y;
            arr[x]=y;
        }
        else{
            cin>>i;
            edges[i].x=0;
        }
        //Graph construction
        graph.clear();
        graph.resize(n+1);
        for(i=1;i<=m;i++){
            if (edges[i].x==0)continue;
            graph[edges[i].x].push_back(edges[i].y);
            graph[edges[i].y].push_back(edges[i].x);
        }
        for(i=1;i<=n;i++)visited[i]=false;
        ans=0;
        for(i=1;i<=n;i++){
            if(!visited[i]){
                visited[i]=true;
                ans=max(ans,arr[i]+dfs(i));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
