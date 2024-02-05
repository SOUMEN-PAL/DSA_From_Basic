#include<bits/stdc++.h>
using namespace std;

class Node {
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

Node *reverse(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *removeStartingZeroes(Node *head){
    Node *curr = head;
    while(curr != NULL && curr->data == 0){
        curr = curr->next;
    }
    return curr;
}

int main(){
    Node *head = new Node(0);
    Node *temp1 = new Node(0);
    Node *temp2 = new Node(0);
    Node *temp3 = new Node(4);
    Node *temp4 = new Node(5);
    Node *temp5 = new Node(6);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;

    Traverse(head);
    head = removeStartingZeroes(head);
    Traverse(head);
    head = reverse(head);
    Traverse(head);
    
        
    return 0;
}