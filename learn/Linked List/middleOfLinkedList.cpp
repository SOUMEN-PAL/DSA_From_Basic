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

void Traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
//  Efficient solution //
int MiddleOfLinkedList(Node* head){
    if(head == NULL || head->next == NULL){
        return head == NULL ? 0 : head->data;
    }

    Node* curr = head;
    Node* mid = head;

    while(curr != NULL && curr->next != NULL){
        mid = mid->next;
        curr = curr->next->next;
    }
    return mid->data;

}


int main(){
    Node* head = new Node(10);
    Node* h2 = new Node(20);
    Node* h3 = new Node(30);
    Node* h4 = new Node(40);
    Node* h5 = new Node(50);
    Node* h6 = new Node(60);
    Node* h7 = new Node(70);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;

    cout<<MiddleOfLinkedList(head)<<endl;
    return 0;
}