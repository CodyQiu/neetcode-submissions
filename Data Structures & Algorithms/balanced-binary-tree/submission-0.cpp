/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int temp = 1 + max(height(root->left), height(root->right));
        return temp;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int lheight = height(root->left);
        int rheight = height(root->right);
        bool curr;
        bool prev;
        if (abs(lheight - rheight) > 1) curr = false;
        else curr = true;
        prev = isBalanced(root->left) && isBalanced(root->right);
        return prev && curr;
    }
};
