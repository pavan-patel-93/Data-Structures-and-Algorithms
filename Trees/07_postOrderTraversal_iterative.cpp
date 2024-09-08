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
            vector<int> postOrder;
            if(root == NULL) return postOrder;

            stack<TreeNode*> st1;
            stack<TreeNode*> st2;

            st1.push(root);
            while(!st1.empty()){
                TreeNode* node = st1.top();
                st1.pop();
                st2.push(node);

                if(node->left) st1.push(node->left);
                if(node->right) st1.push(node->right);
            }          

            while(!st2.empty()){
                postOrder.push_back(st2.top()->val);
                st2.pop();
            } 
            return postOrder;
        } 

        vector<int> iterativePostOrderTraversalUsingSingleStack(TreeNode* root){
            vector<int> postOrder;
            if(root == NULL) return postOrder;

            stack<TreeNode*> st;
            st.push(root);
            TreeNode* current = root;

            while(current != NULL || !st.empty()){
                if(current != NULL){
                    st.push(current);
                    current = current -> left;
                }else{
                    TreeNode* tempNode = st.top()->right;
                    st.pop();
                    postOrder.push_back(tempNode->val);
                    while(!st.empty() && tempNode == st.top() -> right){
                        tempNode = st.top();
                        st.pop();
                        postOrder.push_back(tempNode->val);
                    }
                }
            }
            return postOrder;
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

    // Using two stacks
    vector<int> result = sol.iterativePostOrderTraversalUsingTwoStack(root);

    // Using single stack
    // vector<int> result = sol.iterativePostOrderTraversalUsingSinfleStack(root);
    for(auto i: result){
        cout << i << " ";
    }
    cout << endl;
}