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
    void traverse(TreeNode* root, vector<int> &group, int depth) {
        if (root == nullptr) return;
        if (group.size() < depth + 1) group.push_back(root->val);
        traverse(root->right, group, depth + 1);
        traverse(root->left, group, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> group;
        traverse(root, group, 0);
        return group;
    }
};
