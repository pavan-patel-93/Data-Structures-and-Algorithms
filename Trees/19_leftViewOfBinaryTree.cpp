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
    void traverse(TreeNode* node, int level, vector<int>& res){
        if(node == NULL) return;

        if(level == res.size()) res.push_back(node->val);

        if(node->left) traverse(node->left, level+1, res);
        if(node->right) traverse(node->right, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        traverse(root, 0, res);
        return res;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);

    Solution sol;
    vector<int> ans = sol.rightSideView(root);

    for(auto node: ans){
        cout << node << " ";
    }
}