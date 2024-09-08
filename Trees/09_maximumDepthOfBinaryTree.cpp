#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{
    public:
        int maxDepth(TreeNode* root){
           if(root == NULL) return 0;

           int leftHeight = maxDepth(root->left);
           int rightHeight = maxDepth(root->right);

           return 1 + max(leftHeight, rightHeight);
        } 
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);
    root->right->right->left->right = new TreeNode(8);

    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "The maximum depth of the binary tree : " << depth << endl;
}