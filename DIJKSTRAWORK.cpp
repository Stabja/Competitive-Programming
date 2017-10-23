#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define pb push_back

int n, e;
vector<ii> g[3002];
int dist[3002];
bool marked[3002];

void apply_dijkstra(int source)
{
	set<ii > s;
	s.insert(ii(0,source));
	dist[source] = 0;
	marked[source] = 1;
	while(!s.empty())
	{
		ii p = *s.begin();
		int v = p.second;
		s.erase(p);
		marked[v] = 1;
		for(int i = 0; i < g[v].size(); i++){
            int w = g[v][i].second;   //Neighboring Node
            int d = g[v][i].first;    //Distance
			if(marked[w] == 0)       //If not visited, insert in the set
			{
				s.insert(ii(dist[v]+d, w));
				marked[w] = 1;
				dist[w] = dist[v]+d;
			}
			else if(marked[w] ==1 && dist[w] > dist[v]+d)  //If better path found, update the distance
			{                                              //If priority queue was used, this else condition can be avoided
				s.erase(ii(dist[w], w));
				s.insert(ii(dist[v]+d, w));
                dist[w] = dist[v]+d;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
	    if(i == source)  continue;
	    cout<<dist[i]<<" ";
	}
	cout<<"\n";
}


int main()
{
    int source, T;
    cin>>T;
    while(T--){
        memset(dist, -1, sizeof dist);
        memset(marked, false, sizeof marked);
        scanf("%d%d",&n, &e);
	    for(int i = 0; i < e; i++)
	    {
		    int x, y, w;
		    scanf("%d%d%d", &x, &y, &w);
		    g[x].pb(ii(w, y));
		    g[y].pb(ii(w, x));
	    }
	    scanf("%d", &source);
	    apply_dijkstra(source);
	    for(int i = 0; i < 3000; i++){
            g[i].clear();
	    }
    }
	return 0;
}
