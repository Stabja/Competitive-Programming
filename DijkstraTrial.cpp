#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

set<pair<int, int> > maps;
map<int, int> S;
vector<pair<int, int> > vertices[100];
int dist[100];
bool removed[100];

void display(){
    for(map<int, int>::iterator it = S.begin(); it != S.end(); ++it){
        cout<<(*it).first<<" "<<(*it).second<<"\n";
    }
    cout<<"\n";
}

bool compare(pair<int, int> a, pair<int, int> b){
    return (a.second < b.second);
}

void ApplyDijkstra(int src){
    dist[src] = 0;
    set<pair<int, int> >::iterator it = find(maps.begin(), maps.end(), src);
    temp = *it;
    temp.second = dist[src];

    while(!maps.empty()){
        sort(maps.begin(), maps.end(), compare);
        vector<pair<int, int> >::iterator it2 = maps.begin();   //ExtractMin
        int v = (*it2).first;
        maps.erase(it2);
        removed[v] = true;
        for(int i = 0; i < vertices[v].size(); i++){   //all the neighbors of v
            int w = vertices[v][i].first;
            int d = vertices[v][i].second;
            if(!removed[w]){                 //if w is present in list
                vector<pair<int, int> >::iterator it3 = find(maps.begin(), maps.end(), w);
                dist[w] = min(dist[w], dist[v] + d);
                //(*it3).second = dist[w];
            }
        }
    }
}

/*void ApplyDijkstra(int src){
    dist[src] = 0;
    S[src] = 0;        //DecreasePriority
    while(!S.empty()){
        //sort(S.begin(), S.end(), compare);
        map<int, int>::iterator it = S.begin();
        int v = (*it).first;
        S.erase(it);
        removed[v] = true;
        for(int i = 0; i < vertices[v].size(); i++){
            int w = vertices[v][i].first;
            int d = vertices[v][i].second;
            if(!removed[w]){
                dist[w] = min(dist[w], dist[v] + d);
                S[w] = dist[w];
            }
        }
    }
}*/

int main(){
    int V, E;
    cin>>V>>E;
    int x, y, w, source;
    for(int i = 1; i <= E; i++){
        cin>>x>>y>>w;
        vertices[x].push_back(make_pair(y, w));
        vertices[y].push_back(make_pair(x, w));
    }
    //Inserting in 'maps' set
    //memset(dist, 10000, sizeof dist);
    for(int i = 1; i <= V; i++){
        dist[i] = 10000;
        //S[i] = dist[i];
        maps.insert(make_pair(i, dist[i]));
    }

    //sort(maps.begin(), maps.end(), compare);
    cin>>source;
    ApplyDijkstra(source);
    for(int i = 1; i <= V; i++){
        cout<<i<<" "<<dist[i]<<"\n";
    }
    return 0;
}
