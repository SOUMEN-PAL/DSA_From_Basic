#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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


int size(Node * root){
    if(root == NULL){
        return 0;
    }

    else{
        return 1 + size(root->left) + size(root->right);
    }
}


// Itreative solution //
int treeSize(Node * root){
    if(root == NULL){
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    int count = 1;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(curr->left != NULL){
            count++;
            q.push(curr->left);
        }
        if(curr->right != NULL){
            count++;
            q.push(curr->right);
        }
    }
    return count;

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

    cout<<size(root)<<" "<<treeSize(root)<<endl;

    return 0;
}