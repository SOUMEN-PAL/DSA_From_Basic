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


const int EMPTY = NULL;
void slz(Node * root , vector<int> &arr){
    if(root == NULL){
        arr.push_back(EMPTY);
        return;
    }

    arr.push_back(root->data);
    slz(root->left , arr);
    slz(root->right , arr);
}

Node * deSerealize(vector<int> arr , int &index){
    if(index == arr.size()){
        return NULL;
    }
    int element = arr[index];
    index++;
    Node *root;
    if(element == EMPTY){
        return NULL;
    }

    root = new Node(element);

    root->left = deSerealize(arr, index);
    root->right = deSerealize(arr , index);
    return root;
}

void preOrder(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main(){
    Node *root = new Node(1);
    Node *l1 = new Node(2);
    Node *r1 = new Node(3);
    Node *l2 = new Node(4);
    Node *r2 = new Node(5);
    Node *l3 = new Node(6);

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;

    vector<int> arr;
    slz(root , arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    int index = 0;
    Node *tree = deSerealize(arr , index);
    preOrder(tree);


    return 0;
}