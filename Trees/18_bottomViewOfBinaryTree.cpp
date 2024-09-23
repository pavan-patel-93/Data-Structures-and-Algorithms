#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data = value;
        left = right = nullptr;
    };
};

class Solution{
    public:
    vector<int> bottomViewBinaryTee(TreeNode* root){
        vector<int> bottomView;
        if(root == NULL)  return bottomView;
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int line = it.second;
            mp[line] = node->data;
            if(node->left != NULL) q.push({node->left, line - 1});
            if(node->right != NULL) q.push({node->right, line + 1});
        }


        for(auto i:mp) {
            bottomView.push_back(i.second);
        }
        return bottomView;
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
    vector<int> ans = sol.bottomViewBinaryTee(root);

    for(auto node: ans){
        cout << node << " ";
    }
    
}