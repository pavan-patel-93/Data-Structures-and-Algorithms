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
    int getMaximumPathSum(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int leftSum = max(0, getMaximumPathSum(root->left, maxi));
        int rightSum = max(0, getMaximumPathSum(root->right, maxi));

        maxi = max(maxi, (root->data  + leftSum + rightSum));

        return root->data + max(leftSum, rightSum);
    }
};


int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int maximumPathSum = INT_MIN;
    sol.getMaximumPathSum(root, maximumPathSum);
    cout << "Maximum path sum is :: " << maximumPathSum << endl; 
}