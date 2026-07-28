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

    int maxPathSum(TreeNode* root, int &largest) {
        if (root == nullptr) return 0;
        int left = maxPathSum(root->left, largest);
        int right = maxPathSum(root->right, largest);
        largest = max({largest, left + root->val, right + root->val, root->val, left + right + root->val});
        return max({root->val, left + root->val, right + root->val});
    }

    int maxPathSum(TreeNode* root) {
        int largest = INT_MIN;
        maxPathSum(root, largest);
        return largest;
    }
};
