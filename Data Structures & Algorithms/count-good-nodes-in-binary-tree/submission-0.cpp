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
    void goodNodes(TreeNode* root, int largest, int &total) {
        if (root == nullptr) return;
        if (root->val >= largest) {
            largest = max(largest, root->val);
            total += 1;
        }
        goodNodes(root->left, largest, total);
        goodNodes(root->right, largest, total);
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int total = 0;
        goodNodes(root, root->val, total);
        return total;
    }
};
