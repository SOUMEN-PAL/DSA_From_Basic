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
void printLinkedList(Node* head){
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


Node* insertAtEnd(Node *head , int x){
    if(head == NULL){
        return new Node(x);
    
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(x);
    return head;
}


Node* reverse(Node* head){
    Node* curr = head;
    Node*next = head;
    Node* prev = NULL;

    while(curr != NULL){
        curr = curr->next;
        next->next = prev;
        prev = next;
        next = curr;
    }
    return prev;
}


int main(){
    
    Node*head = insertAtEnd(NULL , 1);
    head = insertAtEnd(head , 2);
    head = insertAtEnd(head , 3);
    head = insertAtEnd(head , 4);
    head = insertAtEnd(head , 5);

    printLinkedList(head);
    head = reverse(head);
    printLinkedList(head);

    return 0;
}