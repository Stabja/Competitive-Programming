#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V])
{
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshell (int graph[][V])
{
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    }
    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

int main()
{
    int graph[V][V] = { {0, 1, 1, INF},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1},
                        {INF, 1, 1, 0}
                      };
    floydWarshell(graph);
    return 0;
}
