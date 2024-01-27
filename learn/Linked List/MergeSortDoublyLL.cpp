#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next,*prev;
        Node(int x){
            data=x;
            next=prev=NULL;
        }
};


Node* mid(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    Node *slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }    
    return slow;
}

Node* merge(Node* left , Node* right){

    Node *head=NULL,*tail=NULL;
    if(left->data<=right->data){
        head=tail=left;
        left=left->next;
    }
    else{
        head=tail=right;
        right=right->next;
    }
    while(left!=NULL && right!=NULL){
        if(left->data<=right->data){
            tail->next=left;
            left->prev=tail;
            tail=left;
            left=left->next;
        }
        else{
            tail->next=right;
            right->prev=tail;
            tail=right;
            right=right->next;
        }
    }
    if(left!=NULL){
        tail->next=left;
        left->prev=tail;
    }
    else{
        tail->next=right;
        right->prev=tail;
    }
    return head;
}

Node* mergeSort(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    Node *midNode=mid(head);
    Node *nextToMid=midNode->next;
    midNode->next=NULL;
    nextToMid->prev=NULL;
    Node *left=mergeSort(head);
    Node *right=mergeSort(nextToMid);
    return merge(left,right);
}


void Traverse(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(90);
    Node *temp2=new Node(30);
    Node *temp3=new Node(20);
    Node *temp4=new Node(40);

    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    temp2->next=temp3;
    temp3->prev=temp2;
    temp3->next=temp4;
    temp4->prev=temp3;

    Traverse(head);
    head=mergeSort(head);
    Traverse(head);


    return 0;
}