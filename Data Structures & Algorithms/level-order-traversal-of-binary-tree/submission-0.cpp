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
    void makeList(TreeNode* root, vector<vector<int>> &lists, int curr) {
        if (root == nullptr) return;
        if (lists.size() < curr + 1) lists.push_back({root->val});
        else lists[curr].push_back(root->val);
        makeList(root->left, lists, curr + 1);
        makeList(root->right, lists, curr + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lists;
        makeList(root, lists, 0);
        return lists;
    }
};
