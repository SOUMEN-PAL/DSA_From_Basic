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
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


Node* swapkthNode(Node* head , int n , int k){
    if(head == NULL){
        return head;
    }
    if(k>n){
        return head;
    }    

    Node* x = head;
    Node* preX = NULL;
    Node* y = head;
    Node* preY = NULL;

    for(int i = 1 ; i<k ; i++){ 
        preX = x;
        x = x->next;
    }

    for(int i = 1 ; i<=n-k ; i++){
        preY = y;
        y = y->next;
    }

    if(preX != NULL){
        preX->next = y;
    }else{
        head = y;
    }

    if(preY != NULL){
        preY->next = x;
    }else{
        head = x;
    }
    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    return head;
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
    head = swapkthNode(head , 6 , 1);
    traverse(head);



    return 0;
}