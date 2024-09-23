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
    bool isSameTree(TreeNode* p, TreeNode* q){

        if(p == NULL || q == NULL) return p==q;
        return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};


int main(){
    // Tree P
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->left = new TreeNode(4);
    p->right->right = new TreeNode(5);

    // Tree q
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->right->left = new TreeNode(4);
    q->right->right = new TreeNode(5);

    Solution sol;
    bool isSameTree = sol.isSameTree(p, q);
    cout << (isSameTree ? "Tree p and Tree q are similar trees" : "Trees are not same") << endl;
}
    