#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int arr[100005];

struct Node{
    int data;
    Node* next;
}*start, *prev, *ptr;


void insert(int data){
    ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;
    if(start == NULL){
        start = prev = ptr;
    }
    else{
        prev->next = ptr;
        prev = ptr;
    }
}

void remove(Node* ptr1){
    if(ptr1 == NULL){
        return;
    }
    Node *temp = start;
    while(temp->next != ptr1)
        temp = temp->next;

    temp->next = ptr1->next;
    delete ptr1;
}

void removeByVal(int pos){
    Node *temp = start;
    int k = 2;
    while(k != pos){
        k++;
        temp = temp->next;
    }
    temp->next = temp->next->next;
    delete temp->next;
}

void display(){
    ptr = start;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<"\n";
}


int main(){
    /*insert(6);
    insert(5);
    insert(8);
    insert(4);
    insert(7);
    insert(10);
    insert(9);
    display();
    removeByVal(4);
    display();
    removeByVal(2);
    display();
    removeByVal(3);
    display();*/

    int n;
    cin>>n;
    int x;
    for(int i = 0; i < n; i++){
        cin>>x;
        insert(x);
    }
    display();
    int cnt = 0;
    ptr = start;
    cnt = 0;
    while(ptr->next != NULL){
        int save = ptr->data;
        while(ptr->next->data > save){
            save = ptr->next->data;
            //remove(ptr->next);
            ptr->next = ptr->next->next;
            delete ptr->next;
            cnt++;
        }
        ptr = ptr->next;
    }
        display();

    return 0;
}
