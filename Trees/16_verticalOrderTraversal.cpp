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

    vector<vector<int>> verticalOrderTraversal(TreeNode* root){

        // Prepare the map <vertical , pair: <level, multiSet<nodes->val>>> nodes
        map<int, map<int, multiset<int>>> nodes;


        // Prepare the queue <pair<node, pair<vertical, level>>> 
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while(!todo.empty()){
            auto x = todo.front();
            todo.pop();
            TreeNode* node = x.first;
            int vertical = x.second.first;
            int level = x.second.second;

            nodes[vertical][level].insert(node->data);

            if(node->left != NULL) todo.push({node->left, {vertical-1, level+1}});
            if(node->right != NULL) todo.push({node->right, {vertical+1, level+1}});
        }


        vector<vector<int>> ans;

        for(auto p: nodes){
            vector<int> column;
            for(auto q: p.second){
                column.insert(column.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
    
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> ans = sol.verticalOrderTraversal(root);
    cout << "============= VERTICAL ORDER TRAVERSAL =============\n";
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
    }
    cout << "\n=============================================" << endl;
}