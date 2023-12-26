#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

void traverse(Node* head){
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void rec_tra(Node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    rec_tra(head->next);

}

int main(){
    
    Node*head = new Node(1);
    Node* temp1 = new Node(2);
    Node* temp2 = new Node(3);
    Node* temp3 = new Node(4);
    Node* temp4 = new Node(5);
    Node* temp5 = new Node(6);
    Node* temp6 = new Node(7);
    Node* temp7 = new Node(8);
    Node* temp8 = new Node(9);
    Node* temp9 = new Node(10);
    Node* temp10 = new Node(11);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp6;
    temp6->next = temp7;
    temp7->next = temp8;
    temp8->next = temp9;
    temp9->next = temp10;


    traverse(head);
    cout<<endl;
    rec_tra(head);

    return 0;
}