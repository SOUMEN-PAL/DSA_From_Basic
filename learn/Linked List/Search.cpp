#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        
        Node *next;

        Node(int x){
            data = x;
            next = NULL;
        }


};

void traverse(Node*head){
    if(head == NULL){
        cout<<"Empty";
        return;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int Search(Node *head , int x){
    int c = 1;
    Node* curr = head;
    while(curr != NULL){
        if(curr->data != x){
            c++;
            curr = curr->next;
        }
        else{
            return c;
        }
        
    }
    return -1;
}

int searchRec(Node* head , int x){
    if(head==NULL){
        return -1;
    }
    if(head->data == x){
        return 1;
    }
    else{
        int res = searchRec(head->next , x);
        if(res == -1){
            return -1;
        }
        else{
            return res+1;
        }
    }
}

int main(){

    Node *head = new Node(1);
    Node *t1 = new Node(2);
    Node *t2 = new Node(3);
    Node *t4 = new Node(4);
    Node *t5 = new Node(5);
    Node *t6 = new Node(6);
    Node *t7 = new Node(7);
    Node *t8 = new Node(8);
    Node *t9 = new Node(9);

    head->next = t1;
    t1->next = t2;
    t2->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = t7;
    t7->next = t8;
    t8->next = t9;

    traverse(head);
    cout<<Search(head , 40)<<endl;
    cout<<searchRec(head , 40)<<endl;




    return 0;
}