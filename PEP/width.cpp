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




void verticalTraversal(Node *root , vector<vector<int>> &arr , int i){

    if(root == NULL){
        return;
    }

    arr[(i+ 4) % 4].push_back(root->data);
    verticalTraversal(root->left , arr , i-1);
    verticalTraversal(root->right , arr , i+1);

}

vector<vector<int>> verticalTraversalLevelOrder(Node *root , vector<vector<int>> &arr){

    queue<pair<Node* , int>> q;
    q.push({root , 0});

    while(!q.empty()){
        pair<Node* , int> p = q.front();
        q.pop();

        Node *temp = p.first;
        int i = p.second;

        arr[(i+4) % 4].push_back(temp->data);

        if(temp->left){
            q.push({temp->left , i-1});
        }

        if(temp->right){
            q.push({temp->right , i+1});
        }
    }

    return arr;
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

    vector<vector<int>> arr(4);
    verticalTraversal(root , arr , 0);



    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[i].size() ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    vector<vector<int>> arr1(4);
    arr1 = verticalTraversalLevelOrder(root , arr1);

    for(int i=0 ; i<arr1.size() ; i++){
        for(int j=0 ; j<arr1[i].size() ; j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}