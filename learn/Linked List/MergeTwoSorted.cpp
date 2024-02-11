#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        }
};

Node *mergeSorted(Node *head1 , Node *head2){
    Node *head = NULL , *tail = NULL;
    if(head1->data < head2->data){
        head = tail = head1;
        head1 = head1->next;
    }
    else{
        head = tail = head2;
        head2 = head2->next;
    }
    while(head1 != NULL && head2 != NULL){
        if(head1->data<head2->data){
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        else{
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
            
        }
        
    }

    if(head1 != NULL){
        tail->next = head1;
    }
    else if(head2 != NULL){
        tail->next = head2;
    }

    return head;
}


void Traverse(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int main(){

    Node* head1 = new Node(1);
    Node* h2 = new Node(2);
    Node* h3 = new Node(3);
    Node* h4 = new Node(4);
    Node* h5 = new Node(5);
    Node* h6 = new Node(6);

    head1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;

    Node *head2 = new Node(2);
    Node *h7 = new Node(3);
    Node *h8 = new Node(4);
    Node *h9 = new Node(5);
    Node *h10 = new Node(6);
    Node *h11 = new Node(7);

    head2->next = h7;
    h7->next = h8;
    h8->next = h9;
    h9->next = h10;
    h10->next = h11;

    Traverse(head1);
    Traverse(head2);

    Node *head = mergeSorted(head1 , head2);
    Traverse(head);


    return 0;
}