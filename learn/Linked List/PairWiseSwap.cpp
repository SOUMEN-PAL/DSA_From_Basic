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

void Traverse(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Naive Solution //
Node *swapPairWise(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *curr = head;
    while(curr != NULL && curr->next != NULL){
        swap(curr->data , curr->next->data);
        curr = curr->next->next;
    }
    return head;
}

// Efficient Solution //

Node *swapNodes(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *curr = head->next->next;
    Node * prev = head;
    head = head->next;
    head->next = prev;
    while(curr != NULL && curr->next != NULL){
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next; // getting the hold of the up comming nodes //
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
    
}

int main(){
    
    Node *head = new Node(1);
    Node *temp1 = new Node(2);
    Node *temp2 = new Node(3);
    Node *temp3 = new Node(4);
    Node *temp4 = new Node(5);
    Node *temp5 = new Node(6);
    Node *temp6 = new Node(7);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp6;

    Traverse(head);
    head = swapPairWise(head);
    Traverse(head);
    head = swapNodes(head);
    Traverse(head);

    return 0;
}