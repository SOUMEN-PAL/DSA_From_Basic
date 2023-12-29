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


Node* insertAtEnd(Node *head , int x){
    if(head == NULL){
        return new Node(x);
    
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(x);
    return head;
}

Node* insertAtIndex(Node*head , int x , int pos){
    Node* t = new Node(x);

    if(pos == 1){
        t->next = head;
        return t;
    }

    Node* curr = head;
    for(int i = 1 ; i<= pos - 2 ; i++){
        curr = curr->next;
        if(curr == NULL){
            cout<<"Invalid Position"<<endl;
            return head;
        }
    }

    t->next = curr->next;
    curr->next = t;
    return head;
    
}


void printLinkedList(Node* head){
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


Node * delTail(Node *head){
    if(head == NULL){
        return NULL;
    }

    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
}

Node * delIndex(Node *head , int pos){
    if(head == NULL){
        return NULL;
    }
    if(pos == 1){
        Node *temp = head->next;
        delete head;
        return temp;
    }

    Node *curr = head;
    for(int i = 1 ; i<= pos - 2 ; i++){
        curr = curr->next;
        if(curr == NULL){
            cout<<"Invalid Position"<<endl;
            return head;
        }
    }

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

int searchll(Node *head , int x){
    int c = 1;
    while(head!=NULL){
        if(head->data != x){
            c++;
        }
        else{
            return c;
        }
        head = head->next;
    }
    return -1;
}

int main(){
    
    Node*head = insertAtEnd(NULL , 1);
    head = insertAtEnd(head , 2);
    head = insertAtEnd(head , 3);
    head = insertAtEnd(head , 4);
    head = insertAtEnd(head , 5);

    printLinkedList(head);

    head = insertAtIndex(head , 6 , 4);
    
    printLinkedList(head);

    head = delTail(head);

    printLinkedList(head);

    head = delIndex(head , 5);

    printLinkedList(head);

    cout<<searchll(head , 63);
    return 0;
}