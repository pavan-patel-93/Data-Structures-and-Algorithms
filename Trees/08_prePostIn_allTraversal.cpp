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
        vector<vector<int>> prePostInOrderTraversal(TreeNode* root){
            vector<int> preOrder;
            vector<int> inOrder;
            vector<int> postOrder;
            vector<vector<int>> ans;

            stack<pair<TreeNode*, int>> st;
            st.push({root, 1});

            while(!st.empty()){
                auto it = st.top();
                st.pop();
                if(it.second == 1){
                    preOrder.push_back(it.first->val);
                    it.second++;
                    st.push(it);

                    if(it.first -> left != NULL){
                        st.push({it.first->left, 1});
                    }
                }
                else if(it.second == 2){
                    inOrder.push_back(it.first->val);
                    it.second++;
                    st.push(it);

                    if(it.first -> right != NULL){
                        st.push({it.first->right, 1});
                    }
                }else{
                    postOrder.push_back(it.first->val);
                }
            }

            ans.push_back(preOrder);
            ans.push_back(inOrder);
            ans.push_back(postOrder);

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
    vector<vector<int>> result = sol.prePostInOrderTraversal(root);
    for(auto i: result){
        for(auto x: i){
            cout << x << " ";
        }
        cout << endl;
    }
}