#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define pb push_back
#define mp make_pair

vector<pair<int, int> > vertex[1000];
stack<int> maxFlowPath;
queue<int> neighbors;

int path[1000];
int level[1000];
bool visited[1000];
int max_flow = 0;

bool bfs(int src, int dest);
void calculatePath(int dest);
void printPath(int des);
void reset();
void calculateMaxFlow();

bool bfs(int src, int dest){
    level[src] = 0;
    int w;
    int cap;
    path[src] = 0;
    neighbors.push(src);
    visited[src] = true;
    while(!neighbors.empty()){
        int v = neighbors.front();
        neighbors.pop();
        for(int i = 0; i < vertex[v].size(); i++){
            w = vertex[v][i].first;
            cap = vertex[v][i].second;
            if(!visited[w] && cap > 0){       //Dynamic graph
                visited[w] = true;
                path[w] = v;
                neighbors.push(w);
                level[w] = level[v]+1;
                /*if(w == dest)
                    break;*/
            }
        }
    }
    return visited[dest];
}

void calculatePath(int dest){
    int i = dest;
    maxFlowPath.push(dest);
    while(i != 1){
        i = path[i];
        maxFlowPath.push(i);
    }
}

void printPath(){
    while(!maxFlowPath.empty()){
        cout<<maxFlowPath.top()<<" ";
        maxFlowPath.pop();
    }
    cout<<"\n\n";
}

void reset(){
    while(!maxFlowPath.empty())
        maxFlowPath.pop();
    while(!neighbors.empty())
        neighbors.pop();
    memset(path, 0, sizeof path);
    memset(level, 0, sizeof level);
    memset(visited, false, sizeof visited);
}

void calculateMaxFlow(){
    int capacity[1000];
    int p = 0;
    stack<int> temp;
    temp = maxFlowPath;
    while(!temp.empty()){
        int x = temp.top();
        temp.pop();
        int y = temp.top();
        temp.pop();
        for(int i = 0; i < vertex[x].size(); i++){
            if(vertex[x][i].first == y){
                capacity[p++] = vertex[x][i].second;
            }
        }
        temp.push(y);
    }
    for(int i = 0; i < p; i++)
        cout<<capacity[i]<<" ";
    int flow = capacity[0];
    for(int i = 1; i < p; i++){
        flow = min(flow, capacity[i]);
    }
    max_flow += flow;
    temp = maxFlowPath;
    while(!temp.empty()){
        int x = temp.top();
        temp.pop();
        int y = temp.top();
        temp.pop();
        for(int i = 0; i < vertex[x].size(); i++){
            if(vertex[x][i].first == y){
                vertex[x][i].second -= flow;        //Subtract flow from edge
            }
        }
        for(int i = 0; i < vertex[y].size(); i++){
            if(vertex[y][i].first == x){
                vertex[y][i].second += flow;        //Add flow to reverse edge
            }
        }
        temp.push(y);
    }
}

int main(){
    int V, E;
    cin>>V>>E;
    int x, y, cap;
    for(int i = 1; i <= E; i++){
        cin>>x>>y>>cap;
        vertex[x].pb(make_pair(y, cap));
    }
    int src, dest;
    cin>>src>>dest;
    while(bfs(src, dest)){
        calculatePath(dest);
        calculateMaxFlow();
        cout<<"\n"<<max_flow<<"\n";
        printPath();
        reset();
    }
    cout<<"\n\nFinal Flow - "<<max_flow<<"\n";



    return 0;
}









