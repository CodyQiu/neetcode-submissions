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

    int maxDepth(TreeNode* root, int size) {
        if (root == nullptr) return size;
        size++;
        int leftSize =  maxDepth(root->left, size);
        int rightSize = maxDepth(root->right, size);
        return max(leftSize, rightSize);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int size = 1;
        int leftSize = maxDepth(root->left, size);
        int rightSize = maxDepth(root->right, size);
        return max(leftSize, rightSize);
    }
};
