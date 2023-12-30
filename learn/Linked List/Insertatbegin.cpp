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

void traverse(Node *head){
    if(head == NULL){
        cout<<"Empty"<<endl;
    }
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

Node *insertbegin(Node * head , int x){
    Node* temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    temp->next = head;
    head->prev = temp;
    return temp;
}


int main(){
    Node *head = new Node(1);
    Node *t1 = new Node(2);
    Node *t2 = new Node(3);

    head->next = t1;
    t1->prev = head;
    t1->next = t2;
    t2->prev = t1;


    head = insertbegin(head , 0);

    traverse(head);
    return 0;
}