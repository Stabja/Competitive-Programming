#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<pair<int, int> > edges;

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

void* merge(Node* x, Node* y)
{
    x = find(x);
    y = find(y);

    if(x->data == y->data)
        return 0;

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

int main(){
    int V, E, flag = 0;
    cin>>V>>E;
    for(int i = 0; i < E; i++){
        int x, y;
        cin>>x>>y;
        edges.push_back(make_pair(x, y));
    }
    Node node[100];
    for(int i = 1; i <= V; i++){
        node[i].data = i;
    }
    for(int i = 0; i < edges.size(); i++){
        int r1 = find(&node[edges[i].first])->data;
        int r2 = find(&node[edges[i].second])->data;
        if(r1 == r2){
            cout<<"Cycle is present at "<<r1;
            flag = 1;
            break;
        }
        merge(&node[edges[i].first], &node[edges[i].second]);
    }
    if(!flag){
        cout<<"No Cycle";
    }
    return 0;
}
