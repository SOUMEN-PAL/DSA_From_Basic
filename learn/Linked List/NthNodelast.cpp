#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int x){
            data=x;
            next=NULL;
        }
};


void Traverse(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
// Naive solution //
void NthNode(Node* head , int k){
    int temp = 0;
    for(auto curr = head ; curr != NULL ; curr = curr->next){
        temp++;
    }
    if(temp<k){
        return;
    }
    Node* curr = head;
    for(int i = 1 ; i<=temp-k ; i++){
        curr = curr->next;
    }
    cout<<curr->data<<endl;

}

//______________ Method 2 ________________//
void NthNodeMethod2(Node* head , int k){
    if(head == NULL){
        return;
    }
    Node* first = head;
    for(int i = 1 ; i<=k ; i++){
        if(first == NULL){
            return; 
        }
        first = first->next;
    }
    Node* second = head;
    while(first != NULL){
        second = second->next;
        first = first->next;
    }
    cout<<second->data<<endl;
    return;
}

int main(){
    Node *head=new Node(1);
    Node *temp1=new Node(2);
    Node *temp2=new Node(3);
    Node *temp3=new Node(4);
    Node *temp4=new Node(6);
    Node *temp5=new Node(5);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;

    Traverse(head);    
    NthNode(head , 2);
    NthNodeMethod2(head , 2);
    return 0;
}