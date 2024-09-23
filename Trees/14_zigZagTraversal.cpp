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
    vector<vector<int>> zigZagTraversal(TreeNode* root){
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool isLeftToRightDirection = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();

                int idx = isLeftToRightDirection ? i : size-i-1;
                level[idx] = node->data;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            isLeftToRightDirection = !isLeftToRightDirection;
            res.push_back(level);
        }
        return res;
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
    vector<vector<int>> ans = sol.zigZagTraversal(root);
    cout << "============= ZIG ZAG TRAVERSAL =============\n";
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
    }
    cout << "\n=============================================" << endl;
}