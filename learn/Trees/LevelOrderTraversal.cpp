#include<bits/stdc++.h>
using namespace std;


// Define Tree structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};


// Naive solution //
int height(Node *root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left) , height(root->right))+1;
}

void printKthFromRoot(Node *root , int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
    }

    printKthFromRoot(root->left , k-1);
    printKthFromRoot(root->right , k-1);
    
}

void leverOrder(Node *root){
    int h = height(root);
    for(int i = 0 ; i<h ; i++){
        printKthFromRoot(root , i);
        cout<<endl;
    }
}


// Efficient SOlution //
// the idea is to use the queue to fill and pop until the tree is entierly traversed //

void BFT(Node *root){
    if(root == NULL){
        // Empty tree;
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }

    }
}


// Naive for line by line //
void levelOrderLine(Node *root)
{
    if(root == NULL){
        return;
    }

    queue<Node *> q; // Not storing the int value just because we dont wanna confure repeated int with Nodes//
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){
            cout<<"\n";
            q.push(NULL);
            continue;            
        }
        cout<<curr->data<<" ";
        if(curr->left != NULL)
        {
            q.push(curr->left);
        }
        if(curr->right != NULL)
        {
            q.push(curr->right);
        }
        
    }
}


// Efficient Line by Line //

void levelOrderLineByLine(Node * root){
    if(root == NULL){
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        
        int count = q.size();
        for(int i = 0 ; i<count ; i++){
            Node *curr = q.front();
            cout<<curr->data<<" ";
            q.pop();
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        cout<<endl;
    }

}



int main(){

    Node *root = new Node(10);
    Node *l1 = new Node(20);
    Node *r1 = new Node(30);
    Node *l2 = new Node(40);
    Node *r2 = new Node(50);
    Node *l3 = new Node(60);
    Node *r3 = new Node(70);
    Node *l4 = new Node(80);
    Node *r4 = new Node(90);

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;
    r1->right = r3;
    l2->left = l4;
    l2->right = r4;
    
    // leverOrder(root);
    levelOrderLineByLine(root);

    return 0;
}