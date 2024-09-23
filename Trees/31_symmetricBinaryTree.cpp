#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        val = value;
        left = right = nullptr;
    };
};

class Solution{
    public:
    bool isSymmetricTree(TreeNode* root){
        return root == NULL || isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        if(left->val != right->val) return false;

        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    Solution sol;
    bool isSymmetricTree = sol.isSymmetricTree(root);

    cout << (isSymmetricTree ? "Tree is a symmetric binary tree" : "Not a symmetric tree") << endl;

}