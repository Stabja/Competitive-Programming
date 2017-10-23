#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<pair<int, int> > edges;

struct Edge{
    int u;
    int v;
    int w;
};

class Node{
    public:
        int data;
        int rank;
        Node* parent;
    Node(){
        data = 0;
        rank = 0;
        parent = this;
    }
};

Node* find(Node* n)
{
    if (n != n->parent) {
        n->parent = find(n->parent);
    }
    return n->parent;
}

void merge(Node* x, Node* y)
{
    x = find(x);
    y = find(y);

    if(x->data == y->data)
        return;

    if (x->rank > y->rank) {
        y->parent = x;
        (x->rank)++;
    } else {
        x->parent = y;
        if (x->rank == y->rank) {
            (y->rank)++;
        }
    }
}

bool compare(Edge a, Edge b){
    if(a.w == b.w){
        return (a.u+a.v+a.w) < (b.u+b.v+b.w);
    }
    return a.w < b.w;
}

int main(){
    int V, E;
    cin>>V>>E;
    Edge edges[20000];
    int u, v, w;
    for(int i = 0; i < E; i++){
        cin>>u>>v>>w;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    //int source;
    //cin>>source;
    Node nodes[100005];
    for(int i = 1; i <= V; i++){
        nodes[i].data = i;
    }
    sort(edges, edges+E, compare);
    int sum = 0;
    int maxz = 0;
    for(int i = 0; i < E; i++){
        int x = edges[i].u;
        int y = edges[i].v;
        int z = edges[i].w;
        if(find(&nodes[x])->data != find(&nodes[y])->data){
            sum += z;
            maxz = max(maxz, z);
            merge(&nodes[x], &nodes[y]);
        }
    }
    cout<<sum-maxz<<" "<<maxz;
    return 0;
}
