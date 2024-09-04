#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    private: 
        bool isPath(TreeNode* root, vector<int>& res, int target){
            if(root == NULL) return false;
            
            res.push_back(root->val);

            if(root->val == target) return true;
            if(isPath(root->left, res, target) || isPath(root->right, res, target)) return true;

            res.pop_back();
            return false;
        }
    public:
        vector<int> getRootToNodePath(TreeNode* root, int target){
            vector<int> res;
            isPath(root, res, target);
            return res;
        }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    int target = 7;
    Solution sol;
    vector<int> ans = sol.getRootToNodePath(root, target);
    for(auto i: ans) cout << i << " ";
}