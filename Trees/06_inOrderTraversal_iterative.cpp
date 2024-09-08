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
        vector<int> iterativePostOrderTraversalUsingTwoStack(TreeNode* root){
            vector<int> res;
            stack<TreeNode*> st;

            TreeNode* node = root;
            while(true){
                if(node != NULL){
                    st.push(node);
                    node = node->left;
                }else{
                    if(st.empty()) break;
                    node = st.top();
                    st.pop();
                    res.push_back(node->val);
                    node = node->right;
                }
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
    vector<int> result = sol.iterativePostOrderTraversalUsingTwoStack(root);
    for(auto i: result){
        cout << i << " ";
    }
    cout << endl;
}