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
    
    head->next = h2;
    
    cout<<MiddleOfLinkedList(head)<<endl;
    return 0;
}