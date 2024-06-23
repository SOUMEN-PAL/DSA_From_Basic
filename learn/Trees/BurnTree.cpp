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


int helper(Node * root , int target , bool flag){
    if(root == NULL){
        return 0;
    }

    if(root->data == target){
        flag = true;
    }

    int l = helper(root->left , target , flag) + 1;
    int r = helper(root->right , target , flag) + 1;


    


}



int main(){
    Node *root = new Node(10);
    Node *l1 = new Node(20);
    Node *r1 = new Node(30);
    Node *l2 = new Node(40);
    Node *r2 = new Node(50);
    Node *l3 = new Node(60);

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;

    return 0;
}