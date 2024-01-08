#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
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

Node* deleteBegin(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* curr = head;
    curr = curr->next;
    curr->prev = NULL;
    delete head;
    return curr;
}

Node* deletelast(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next== NULL){
        delete head;
        return NULL;
    }

    Node* curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    Node* lastNode = curr->next;
    curr->next = NULL;
    lastNode->prev = NULL;
    delete lastNode;
    return head;
}

int main(){
    Node *head = new Node(1);
    Node *t1 = new Node(2);
    Node *t2 = new Node(3);

    head->next = t1;
    t1->prev = head;
    t1->next = t2;
    t2->prev = t1;

    traverse(head);
    head = deletelast(head);
    traverse(head);

    return 0;
}