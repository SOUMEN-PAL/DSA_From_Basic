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

void subTreeAdd(Node *root , int d , int k , vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(k == d){
        ans.push_back(root->data);
    }

    subTreeAdd(root->left , d+1 , k , ans);
    subTreeAdd(root->right , d+1 , k , ans);
}

int findTarget(Node *root , Node *target , int k , vector<int> &ans){
    if(root == NULL){
        return -1;
    }

    if(root == target){
        subTreeAdd(root , 0 , k , ans);
        return 1;
    }

    int left = findTarget(root->left , target , k , ans);
    if(left != -1){
        if(left == k){
            ans.push_back(root->data);
        }
        else{
            subTreeAdd(root->right , left + 1 , k , ans);
        }
        return left + 1;
    }

    int right = findTarget(root->right , target , k , ans);

    if(right != -1){
        if(right == k){
            ans.push_back(root->data);
        }
        else{
            subTreeAdd(root->left , right + 1 , k , ans);
        }
        return right + 1;
    }

    return -1;
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

    vector<int> ans;
    findTarget(root , l1 , 1 , ans);
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}