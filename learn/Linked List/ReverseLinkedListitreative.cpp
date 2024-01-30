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


// Naive solution just copying the data //
Node *reverseList(Node * head){
    vector<int> rev;
    for(auto curr = head ; curr != NULL ; curr = curr->next){
        rev.push_back(curr->data);
    }

    for(auto curr = head ; curr != NULL  ; curr = curr->next){
        curr->data = rev.back();
        rev.pop_back();
    }
    return head;
}

// Efficient Iterative solution // 
Node *reverseListEff(Node *head){
    if(head == NULL){
        return NULL;
    }
    Node *curr = head;
    Node *prev = NULL;
    Node *next = head;
    while(curr != NULL){
        curr = curr->next;
        next->next = prev;
        prev = next;
        next = curr;
    }
    return prev;
}

void Traverse(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}


int main(){
    Node *head = new Node(10);
    Node* h2 = new Node(20);
    Node* h3 = new Node(30);
    head->next = h2;
    h2->next = h3;


    Traverse(head);
    head = reverseList(head);
    Traverse(head);
    head = reverseListEff(head);
    Traverse(head);

    return 0;
}