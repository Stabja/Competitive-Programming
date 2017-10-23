#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

struct Node{
    int data;
    Node *left;
    Node *right;
};

int arr[10000];
int tree[10000];
queue<Node*> q;

Node *buildTree(int l, int r){
    if(l >= r){
        return NULL;
    }
    int mid = (l+r)/2;
    Node *root = new Node();
    root->data = arr[mid];
    root->left = buildTree(l, mid);
    root->right = buildTree(mid+1, r);
    return root;
}

void levelTraversal(Node *root){
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    Node *head = buildTree(0, n);
    levelTraversal(head);
    return 0;
}
