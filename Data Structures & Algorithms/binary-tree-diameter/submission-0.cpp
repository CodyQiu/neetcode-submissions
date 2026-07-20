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
    int diameterOfBinaryTree(TreeNode* root, unordered_set<int> &diameters) {
        if (root == nullptr) return -1;
        int left = diameterOfBinaryTree(root->left, diameters) + 1;
        int right = diameterOfBinaryTree(root->right, diameters) + 1;
        diameters.insert(left + right);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        unordered_set<int> diameters;
        int m = diameterOfBinaryTree(root, diameters);
        m = 0;
        for (int i: diameters) m = max(m, i);
        return m;
    }
};
