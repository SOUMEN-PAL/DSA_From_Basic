#include<bits/stdc++.h>
using namespace std;

// Operations of a circular linked list ..
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

// Insertion at the end of a circular linked list //
Node* insertEnd(Node* head , int x){
    Node* temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }

    Node* tail = head;
    while(tail->next != head){
        tail = tail->next;
    }

    temp->next = tail->next;
    tail->next = temp;
    return head;
}

Node* insertEnd_eff(Node* head , int x){
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
    return temp;    
}

// Naive head deletion //
Node* deleteHead(Node* head){
    if(head == NULL){
        return NULL;
    }

    if(head->next == head){
        delete head;
        return NULL;
    }

    Node* curr = head;
    while(curr->next != head){
        curr = curr->next;
    }

    curr->next = head->next;
    delete head;
    return curr->next;
}

// Efficient Head deletion algo //
Node* deleteHeadEff(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == head){
        delete head;
        return NULL;
    }

    Node* curr = head;
    curr = curr->next;
    int t = head->data;
    head->data = curr->data;
    curr->data = t;
    head->next = curr->next;
    delete curr;
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
    head = insertEnd_eff(head , 500);
    
    traverse(head);

    head = deleteHead(head);

    traverse(head);    

    head = deleteHeadEff(head);

    traverse(head);

    return 0;
}