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
    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int lh = dfs(root->left);
        if(lh == -1) return -1;

        int rh = dfs(root->right);
        if(rh == -1) return -1;

        // Or if the absolute difference of lh and rh is greater than 1 then also return the -1
        if(abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBinaryTreeBalanced(TreeNode* root) {
        if(dfs(root) == -1) return false;
        return true;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(8);

    Solution sol;
    if (sol.isBinaryTreeBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}