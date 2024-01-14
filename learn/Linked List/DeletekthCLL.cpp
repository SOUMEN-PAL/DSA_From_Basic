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

// Delete at kth position for the start //

Node* deletekth(Node* head , int k){

    if(head == NULL){
        return NULL;
    }
    if(head->next == head && k == 1){
        delete head;
        return NULL;
    }
    if(k == 1){
        Node* curr = head;
        curr = curr->next;
        int t = head->data;
        head->data = curr->data;
        curr->data = t;
        head->next = curr->next;
        delete curr;
        return head;

    }
    Node* curr = head;
    for(int i = 1 ; i<=k-2 ; i++){
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
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
    head = deletekth(head , 1);
    traverse(head);

    return 0;
}