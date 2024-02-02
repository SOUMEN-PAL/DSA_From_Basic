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


Node *reverse(Node* head , int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *curr = head , *next = NULL , *prev = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    head->next = reverse(next , k);
    
    return prev;
}


Node *reverseInGroups(Node* head , int k){
    Node *curr = head , *prevfirst = NULL;
    bool firstPass = true;


    while(curr != NULL){

        int count = 0;
        Node*first = curr , *prev = NULL , *next = NULL;
        while(curr != NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(firstPass){
            head = prev;
            firstPass = false;
        }
        else{
            prevfirst->next = prev;
        }
        prevfirst = first;


    }
    return head;
}

void traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(10);
    Node* h2 = new Node(20);
    Node* h3 = new Node(30);
    Node* h4 = new Node(40);
    Node* h5 = new Node(50);
    Node* h6 = new Node(60);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;


    traverse(head);
    head = reverseInGroups(head , 3);
    traverse(head);



    return 0;
}