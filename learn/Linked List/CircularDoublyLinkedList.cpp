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

void traverse(Node* head){
    if(head == NULL){
        cout<<"Empty List"<<endl;
    }

    if(head->next == head){
        cout<<head->data<<endl;
        return;
    }

    // Forward Traversal
    Node* curr = head;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr != head);

    cout<<endl;
    // Reverse Traversal
//     Node* tail = head->prev;
//     curr = tail;
//     do{
//         cout<<curr->data<<" ";
//         curr = curr->prev;
//     }while(curr != tail);
    
//     cout<<endl;
}

Node* insertBegin(Node* head , int x){
    Node* temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return temp;

}


Node* insertEnd(Node* head , int x){
    Node* temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return head;

    
}

int main(){

    Node* head = new Node(10);
    Node* h2 = new Node(20);
    Node* h3 = new Node(30);

    head->next = h2;
    h2->prev = head;
    h2->next = h3;
    h3->prev = h2;
    h3->next = head;
    head->prev = h3;

    traverse(head); 

    head = insertBegin(head , 0);

    traverse(head);

    head = insertEnd(head , 40);

    traverse(head);

    return 0;
}