#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int value){
        data = value;
        right = left = nullptr;
    }
};

class Solution {
public:
    int computeHeight(TreeNode* root, int& diameter){
        if(root == NULL) return 0;

        int lh = computeHeight(root->left, diameter);
        int rh = computeHeight(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        computeHeight(root, diameter);
        return diameter;
    }
};


int main() {

    /* Constructed binary tree is
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;    
    cout << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}