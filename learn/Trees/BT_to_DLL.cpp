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


void treeToDoubly(Node *root , Node * &head)
{
    if(root == NULL){
        return;
    }

    static Node* prev = NULL;
    treeToDoubly(root->left , head);
    if(prev == NULL){
        head = root;
    }
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    treeToDoubly(root->right , head);
}

// Gfg Method
Node *BtTODLL(Node *root){
    if(root == NULL){
        return root;
    }

    static Node* prev = NULL;
    Node *head = BtTODLL(root->left);
    if(prev == NULL){
        head = root;
    }
    else{
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    BtTODLL(root->right);
    return head;
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

    Node *head = BtTODLL(root);
    // treeToDoubly(root , head);

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->right;
    }

    return 0;
}