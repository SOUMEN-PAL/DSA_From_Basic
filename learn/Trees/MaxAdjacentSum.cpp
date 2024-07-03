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

//naive recusive approach
unordered_map<Node * , int> hm;
int maxSum(Node *root){
    if(root == NULL){
        return 0;
    }
    if(hm.find(root) != hm.end()){
        return hm[root];
    }
    int inc = root->data;
    if(root->left){
        inc += maxSum(root->left->left);
        inc += maxSum(root->left->right);
    }
    if(root->right){
        inc += maxSum(root->right->left);
        inc += maxSum(root->right->right);
    }
    int exc = maxSum(root->left) + maxSum(root->right);
    hm[root] = max(inc, exc);
    return hm[root];
}


//efficient solution minimisisng overlapping subproblems
pair<int, int> maxSumEfficient(Node *root){
    if(root == NULL){
        pair<int, int> sum(0, 0);
        return sum;
    }
    pair<int, int> l = maxSumEfficient(root->left);
    pair<int, int> r = maxSumEfficient(root->right);
    pair<int, int> sum;
    sum.first = root->data + l.second + r.second;
    sum.second = max(l.first, l.second) + max(r.first, r.second);
    return sum;
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

    cout << maxSum(root) << endl;
    cout << maxSumEfficient(root).first << endl;
    

    return 0;
}