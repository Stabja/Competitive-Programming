#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define ii pair<int, int>
#define pb push_back

struct vertex{
    int y;
    int w;
    int t;
};

int n, e, source, dest;
//vector<pair<int, <pair<int, int>> > g[10000];
vector<vertex> g[4000];
int dist[4000];
int taxiDist[4000];
bool marked[4000];
bool taxiUsed[4000];


void apply_dijkstra()
{
	set<ii > s;
	s.insert(ii(0,source));
	dist[source] = 0;
	taxiDist[source] = 0;
	marked[source] = 1;
	taxiUsed[source] = false;
	while(!s.empty())
	{
		ii p = *s.begin();
		s.erase(p);
		int v = p.second;
		marked[v] = 2;
		for(int i = 0; i < g[v].size(); i++){
            int w = g[v][i].y;         //Neighboring Node
            int d = g[v][i].w;          //Distance
            int t = g[v][i].t;
			if(marked[w] == 0)           //If not visited, insert in the set
			{
				marked[w] = 1;
				dist[w] = dist[v]+d;
                s.insert(ii(dist[w], w));
			}
			else if(marked[w] == 1 && dist[w] > dist[v]+d)      //If better path found, update the distance
			{
                    s.erase(ii(dist[w], w));
				    s.insert(ii(dist[v]+d, w));
				    dist[w] = dist[v]+d;                     //If priority queue was used, this else condition can be avoided
			}
		}
	}
	printf("Shortest Distances are\n");
	for(int i=1;i<=n;i++)
	{
		printf("Node %d - %d\n",i,dist[i]);
	}
	printf("\n");
}


int main()
{
    int T;
	cin>>T;
	while(T--){
        cin>>n>>e;
	    for(int i = 0; i < e; i++)
	    {
		    int x, y, w, t;
		    cin>>x>>y>>w>>t;
		    //g[x].pb(ii(y, ii()));
		    //g[y].pb(ii(w, x));
		    vertex vi1, vi2;
		    vi1.y = y;
		    vi1.w = w;
		    vi1.t = t;
		    vi2.y = x;
		    vi2.w = w;
		    vi2.t = t;
		    //g[x].pb(make_pair(y, make_pair(w, t)));
		    g[x].pb(vi1);
		    g[y].pb(vi2);
	    }
	    printf("Enter the source:\n");
	    cin>>source>>dest;
	    apply_dijkstra();
	    for(int i = 0; i < 3000; i++){
            g[i].clear();
	    }
	    memset(dist, 0, sizeof dist);
	    memset(taxiDist, 0, sizeof taxiDist);
	    memset(marked, false, sizeof marked);
	    memset(taxiUsed, false, sizeof taxiUsed);
	}
	return 0;
}
