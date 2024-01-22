#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
};

void Traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* insertSorted(Node* head , int d){
    Node* temp = new Node(d);
    if(head == NULL){
        return temp;
    }

    if(temp->data <= head->data){
        temp->next = head;
        return temp;
    }

    Node* curr = head;
    while(curr->next != NULL && curr->next->data<temp->data){
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    return head;
}


int main(){
    Node* head = new Node(10);
    Node* h2 = new Node(20);
    Node* h3 = new Node(30);
    Node* h4 = new Node(40);
    Node* h5 = new Node(50);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    
    Traverse(head);

    head = insertSorted(head , 55);

    Traverse(head);


    return 0;
}