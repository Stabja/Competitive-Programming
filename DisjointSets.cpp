#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Node
{
    public:
        int data;
        int rank;
        Node* parent;
        /*Node() : data(0),
            rank(0),
            parent(this) { }*/
        Node(int d){
            data = d;
            rank = 0;
            parent = this;
        }
};

class DisjointSet
{
    public:
        Node* find(Node*);
        void* merge(Node*, Node*); // Union
};

Node* DisjointSet::find(Node* n)
{
    if (n != n->parent) {
        n->parent = find(n->parent);
    }
    return n->parent;
}

void* DisjointSet::merge(Node* x, Node* y)
{
    x = find(x);
    y = find(y);

    if(x->data == y->data)
        return 0;

    if (x->rank > y->rank) {
        y->parent = x;
    } else {
        x->parent = y;
        if (x->rank == y->rank) {
            ++(y->rank);
        }
    }
}

int main(){
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);
    Node e(5);
    Node f(6);
    Node g(7);
    //Node h(8);

    DisjointSet dj;

    /*dj.merge(&a, &b);
    dj.merge(&b, &c);
    dj.merge(&d, &e);
    dj.merge(&f, &g);
    dj.merge(&e, &f);
    dj.merge(&c, &g);*/

    dj.merge(&a, &b);
    dj.merge(&b, &c);
    dj.merge(&e, &f);

    cout<<dj.find(&a)->data<<"\n";
    cout<<dj.find(&b)->data<<"\n";
    cout<<dj.find(&c)->data<<"\n";
    cout<<dj.find(&d)->data<<"\n";
    cout<<dj.find(&e)->data<<"\n";
    cout<<dj.find(&f)->data<<"\n";
    cout<<dj.find(&g)->data<<"\n";

    return 0;
}
