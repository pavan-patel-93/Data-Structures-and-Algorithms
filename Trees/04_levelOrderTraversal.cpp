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
        vector<vector<int>> levelOrderTraversal(TreeNode* root){
            vector<vector<int>> ans;
            queue<TreeNode*> queue;

            queue.push(root);
            while(!queue.empty()){
                vector<int> level;
                int size = queue.size();
                for(int i=0 ; i<size ; i++){
                    TreeNode* node = queue.front();
                    queue.pop();
                    if(node->left != NULL) queue.push(node->left);
                    if(node->right != NULL) queue.push(node->right);
                    level.push_back(node->val);
                }
                ans.push_back(level);
            }
            return ans;
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
    vector<vector<int>> result = sol.levelOrderTraversal(root);
    for(auto i: result){
        for(auto x: i){
            cout << x << " ";
        }
        cout << endl;
    }
}