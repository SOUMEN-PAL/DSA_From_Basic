#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int x){
            data = x;
            next = NULL;
            prev = NULL;
        }
};


void Traverse(Node* head){
    if(head == NULL){
        cout<<"Empty"<<endl;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node *reverse(Node *head){
    Node *temp=NULL;
    Node *curr=head;
    while(curr!=NULL){
        temp=curr->prev;
        
        curr->prev=curr->next;
        
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp!=NULL)head=temp->prev;
    return head;
}

int main(){
    
    Node* head = new Node(10);
    Node* t1 = new Node(20);
    Node* t2 = new Node(30);
    Node* t3 = new Node(40);

    head->next = t1;
    t1->prev = head;
    t1->next = t2;
    t2->prev = t1;
    t2->next = t3;
    t3->prev = t2;

    Traverse(head);

    head = reverse(head);

    Traverse(head);

    return 0;
}