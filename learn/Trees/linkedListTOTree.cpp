#include<bits/stdc++.h>
using namespace std;

// Define Tree structure
class tNode {
public:
    int data;
    tNode* left;
    tNode* right;

    // Constructor
    tNode(int d) {
        data = d;
        left = right = NULL;
    }
};


class Node{
    public:
        int data;
        Node * next;

        Node(int d){
            data = d;
            next = NULL;
        }
};


void LinkedListToTree(Node *head , tNode *&root){
    if(head == NULL){
        root = NULL;
        return ;
    }

    queue<tNode *> q;
    root = new tNode(head->data);
    q.push(root);
    head = head->next;

    while(head){
        
        tNode *curr = q.front();
        q.pop();
        
        tNode *leftChild = NULL , *rightChild = NULL;

        leftChild = new tNode(head->data);
        q.push(leftChild);
        head = head->next;

        if(head){
            rightChild = new tNode(head->data);
            q.push(rightChild);
            head = head->next;
        }

        curr->left = leftChild;
        curr->right = rightChild;

    }

}


void traverse(tNode *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    traverse(root->left);
    traverse(root->right);
}

int main(){
    Node * head = new Node(1);
    Node *h1 = new Node(2);
    Node *h2 = new Node(3);
    Node *h3 = new Node(4);
    Node *h4 = new Node(5);
    Node *h5 = new Node(6);

    head->next = h1;
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;

    tNode *root;
    LinkedListToTree(head , root);
    traverse(root);




    return 0;
}