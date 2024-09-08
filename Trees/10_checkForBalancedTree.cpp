#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findLeftHeight(TreeNode* node) {
        int height = 0; // Initialize height to 0
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* node) {
        int height = 0; // Initialize height to 0
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }

    int __iterative_checkForBalancedTree(TreeNode* root) {
        if (root == nullptr) return 0; // Return 0 for empty trees

        int leftHeight = __iterative_checkForBalancedTree(root->left);
        if (leftHeight == -1) return -1; // If left subtree is not balanced, return -1

        int rightHeight = __iterative_checkForBalancedTree(root->right);
        if (rightHeight == -1) return -1; // If right subtree is not balanced, return -1

        // Check if the current node is balanced
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Return the height of the subtree rooted at the current node
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return __iterative_checkForBalancedTree(root) != -1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    bool result = sol.isBalanced(root);
    if (result) {
        cout << "The given binary tree is balanced" << endl;
    } else {
        cout << "The binary tree is not balanced" << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
