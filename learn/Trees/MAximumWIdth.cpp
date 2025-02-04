#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        unsigned int res = 0;
        queue<pair<unsigned long long, TreeNode*>> q;
        q.push({0, root});

        while (!q.empty()) {
            unsigned int size = q.size();
            unsigned long long minIndex = q.front().first;
            unsigned long long first, last;
            for (unsigned int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                unsigned long long currIndex = curr.first - minIndex;
                TreeNode* node = curr.second;
                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;
                if (node->left) {
                    q.push({2 * currIndex + 1, node->left});
                }
                if (node->right) {
                    q.push({2 * currIndex + 2, node->right});
                }
            }
            if(last-first + 1 > res){
                res = last-first + 1;
            }
        }
        return res;
    }
};