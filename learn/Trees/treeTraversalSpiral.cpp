#include<bits/stdc++.h>
using namespace std;

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


vector<int> zigzag(Node *root){
    vector<int> res;
    queue<Node *> q;
    if(root == NULL){
        return{};
    }
    bool flag = true;
    q.push(root);
    while(!q.empty()){
        vector<int> temp;
        int count = q.size();
        for(int i = 0 ; i<count ; i++){
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        if(flag == true){
            for(auto i : temp){
                res.push_back(i);
            }
            flag = false;
        }
        else{
            reverse(temp.begin() , temp.end());
            for(auto i : temp){
                res.push_back(i);
            }
            flag = true;
        }
        
    }
    return res;
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

    vector<int> res = zigzag(root);

    for(auto i : res){
        cout<<i<<" ";
    }

    return 0;
}

