#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node *next;
}*ptr, *start, *last;

void push(int val){
    ptr = new node;
    ptr->value = val;
    ptr->next = NULL;
    if(start == NULL){
        start = last = ptr;
    }
    else{
        last->next = ptr;
        last = ptr;
    }
}

void vanish(){
    ptr = start;
    while(ptr){

        if(ptr->next == last){
            last = ptr;
            last->next = NULL;
            ptr = ptr->next;
            delete ptr;
        }
    }

}

void display(){
    ptr = start;
    while(ptr){
        cout<<ptr->value<<" ";
        ptr = ptr->next;
    }
    cout<<"\n";
}

int main(){
    push(5);
    push(3);
    push(4);
    push(9);
    push(7);
    push(8);
    display();
    vanish();
    vanish();
    display();
    vanish();
    display();
    return 0;
}
