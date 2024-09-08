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
        vector<int> inOrderTraversal(TreeNode* root){
            vector<int> result;
            traverse(root, result);
            return result;
        }  
    private: 
        void traverse(TreeNode* root, vector<int>& result){
            if(root==NULL) return;
            traverse(root->left, result);
            result.push_back(root->val);
            traverse(root->right, result);
        } 
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<int> result = sol.inOrderTraversal(root);
    for(auto i: result){
        cout << i << " ";
    }
}