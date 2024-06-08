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


Node *traversalToTree(int in[] , int pre[] , int n ,int is , int ie){
    static int preIndex = 0;
    if(is>ie){return NULL;}

    Node *root = new Node(pre[preIndex++]);

    int inIndex = 0;
    for(int i = is ; i<=ie ; i++){
        if(in[i] == root->data){
            inIndex = i;
            break;
        }
    }

    root->left = traversalToTree(in , pre , n , is , inIndex - 1);
    root->right = traversalToTree(in , pre , n , inIndex + 1 , ie);
    return root;
}

void inOrder(Node *root){
    if(root == NULL){return;}
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


int main(){
    Node *root = new Node(10);
    Node *l1 = new Node(20);
    Node *r1 = new Node(30);
    Node *l2 = new Node(40);
    Node *r2 = new Node(50);
    Node *l3 = new Node(30);

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;

    int inOrderArr[] = {40,20,50,10,30,30};
    int preOrderArr[] = {10,20,40,50,30,30};

    Node *head = traversalToTree(inOrderArr , preOrderArr , 6 , 0 , 5);
    inOrder(head);

    return 0;
}