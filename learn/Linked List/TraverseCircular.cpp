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


void traverse(Node* head){
    if(head == NULL){
        cout<<"List empty!"<<endl;
        return;
    }
    if(head->next == head){
        cout<<"Only one Node: ";
        cout<<head->data<<endl;
        return;
    }

    Node* curr = head;
    Node* copyRef = head;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr != copyRef);
    cout<<endl;
}


Node* insertBegin(Node* head , int x){
    Node* temp = new Node(x);\
    if(head == NULL){
        temp->next = temp;
        return temp;
    }

    if(head->next == head){
        temp->next = head;
        head->next = temp;
        return temp;
    }

    // I need to get a reference to the tail //

    Node* curr = head;
    Node* tail = head;

    while(tail->next != curr){
        tail = tail->next;
    }
    tail->next = temp;
    temp->next = curr;
    return temp;

}

// Efficient insertion in circular linked list //
Node* insertBegin_Eff(Node* head , int x){
    Node* temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }

    temp->next = head->next;
    head->next = temp;

    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return head;
}

int main(){
    Node* head = new Node(10);
    Node* h2 = new Node(20);
    Node* h3 = new Node(30);
    Node* h4 = new Node(40);
    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = head;

    traverse(head);
    head = insertBegin_Eff(head , 50);
    head = insertBegin(head , 500);
    
    traverse(head);
    return 0;
}