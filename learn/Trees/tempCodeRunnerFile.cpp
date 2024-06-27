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

int helper(Node *root , int target , int &dist , int &res){
    if(root == NULL){
        return 0;
    }

    if(root->data == target){
        dist = 0;
        int ld = -1 , rd = -1;
        int lh = helper(root->left , target , ld , res);
        int rh = helper(root->right , target , rd , res);

        res = max(res , max(lh , rh));
        return 1 + max(lh , rh);

    }

    int ldist = -1;
    int rdist = -1;

    int lh = helper(root->left , target , ldist , res);
    int rh = helper(root->right , target , rdist , res);

    if(ldist != -1){
        dist = ldist + 1;
        res = max(res , dist + rh);
    }
    else if(rdist != -1){
        dist = rdist + 1;
        res = max(res , lh + dist);
    }

    return max(lh , rh) + 1;

}


int BurnTree(Node *root , int target){
    int res = 0 , dist = -1;
    helper(root , target , dist , res);
    return res;
}

int main(){
    Node *root = new Node(10);
    Node *l1 = new Node(20);
    Node *r1 = new Node(30);
    Node *l2 = new Node(40);
    Node *r2 = new Node(50);
    Node *l3 = new Node(60);
    Node *r4 = new Node(70);

    root->left = l1;
    root->right = r1;

    l1->left = l2;
    l2->right = r2;
    l2->left = l3;
    l3->left = r4;
    

    bool flag = false;
    int h = BurnTree(root , 50);
    cout<<h<<endl;

    return 0;
}