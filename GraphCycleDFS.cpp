#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> graph[1000];
stack<int> path;
bool visited[1005];
int parent[1005];
int start;

bool dfs(int src, int par)
{
	int i;
    visited[src] = true;

    for (i = 0; i < graph[src].size(); ++i)
    {
        int k = graph[src][i];    //Neighbor
        if (!visited[k])
        {
           parent[k] = src;
           if (dfs(k, src))
              return true;
        }
        else if (k != par){
            parent[k] = src;
            start = src;
            return true;
        }
    }
    return false;
}

/*bool checkcycle(int count){
	int i;
	for(i=1;i<count;i++)
        visited[i]=false;
	for (i = 1; i < count; i++)
        if (!visited[i])
          return(dfs(i, -1));

    return false;
}*/

void PrintPath(){
    path.push(start);
    int i = start;
    do{
        path.push(parent [i]);
        i = parent[i];
    }while(i != start);
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }
}

int main(){
    int V, E;
    cin>>V>>E;
    int x, y;
    for(int i = 0; i < E; i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(visited, false, sizeof visited);
    memset(parent, 0, sizeof parent);

    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            bool is = dfs(i, -1);
            if(is){
                cout<<"\nCycle Detected\n";
                PrintPath();
            }
            else{
                for(int i = 1; i <= V; i++){
                    cout<<parent[i]<<" ";
                }
            }
            /*for(int i = 1; i <= V; i++){
                cout<<visited[i]<<" ";
            }*/
            cout<<"\n";
            is = false;
        }
        memset(parent, 0, sizeof parent);
    }

    return 0;
}
