#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node *next;
    Node *prev;

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};


int main(){
    Node *head = new Node(1);
    Node *t1 = new Node(2);
    Node *t2 = new Node(3);

    head->next = t1;
    t1->prev = head;
    t1->next = t2;
    t2->prev = t1;

    return 0;
}