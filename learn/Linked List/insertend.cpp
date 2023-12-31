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

void Traverse(Node *head){
    if(head == NULL){
        cout<<"Empty"<<endl;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertEnd(Node* head , int x){
    Node* temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

int main(){
    Node* head = new Node(10);
    Node* t1 = new Node(20);
    Node* t2 = new Node(30);
    head->next = t1;
    t1->prev = head;
    t1->next = t2;
    t2->prev = t1;
    Traverse(head);
    head = insertEnd(head , 40);
    Traverse(head);
    return 0;
}