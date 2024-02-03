#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        }
};

void Traverse(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Naive Solution //
int intersectionPoint(Node*first , Node*second){
    if(first == NULL || second == NULL || first->next == NULL || second->next == NULL){
        return -1;
    }
    unordered_set<Node *> hs;
    while(first != NULL){
        hs.insert(first);
        first = first->next;
    }

    while(second != NULL){
        if(hs.find(second) != hs.end()){
            return second->data;
        }
        second = second->next;
    }
    return -1;
}

// effecient solution //
int intersectionPointEfficient(Node *first , Node *second){
    int countList1 = 0 , countList2 = 0;
    for(auto currentNode = first ; currentNode != NULL ; currentNode = currentNode->next){
        countList1++;
    }
    for(auto currentNode = second ; currentNode != NULL ; currentNode = currentNode->next){
        countList2++;
    }
    int mvAmmount = abs(countList1 - countList2);
    if(countList1>countList2){
        while(mvAmmount){
            first = first->next;
            mvAmmount--;
        }
    }
    else{
        while(mvAmmount){
            second = second->next;
            mvAmmount--;
        }
    }

    while(first != NULL && second != NULL){
        if(first == second){
            return first->data;
        }
        first = first->next;
        second = second->next;
    }
    return -1;
}

int main(){
    Node *head = new Node(10);
    Node *h2 = new Node(20);
    Node *h3 = new Node(30);
    Node *h4 = new Node(40);
    Node *h5 = new Node(50);
    Node *h6 = new Node(60);
    Node *h7 = new Node(70);
    Node *h8 = new Node(80);
    Node *h9 = new Node(90);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    h7->next = h8;
    h8->next = h9;

    Node *head2 = new Node(100);
    head2->next = h6;

    cout<<"Intersection of the two linked list is: "<<intersectionPointEfficient(head , head2)<<endl;

    return 0;
}