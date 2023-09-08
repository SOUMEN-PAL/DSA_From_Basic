#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
    node(int x){
        data = x;
        next = NULL;
    }
};

void tran(node *head){
    node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

// to insert at begin //
node *insert_begin(node *head , int x)
{
    node *temp = new node(x);
    temp->next = head;
    return temp;
}

// insert at position //
node *Insert_Random(node *head , int pos , int data){
    node *temp = new node(data);
    if(pos == 1){
        temp->next = head;
        return temp;
    }
    node *curr = head;
    for(int i = 1 ; i<=pos-2 && curr != NULL ; i++){
        curr = curr->next;
    }
    if(curr == NULL){
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

node *delhead(node *head){
    if(head == NULL){
        return NULL;
    }
    else{
        node *temp = head->next;
        delete head;
        return temp;
    }
}

node *delTail(node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
}


int main(){
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    node *temp3 = new node(40);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    
    head = delTail(head);
    
    tran(head);
    return 0;
}