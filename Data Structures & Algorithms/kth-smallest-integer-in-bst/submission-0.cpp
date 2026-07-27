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

    void buildNodes(TreeNode* root, vector<int> &nodes) {
        if (root == nullptr) return;
        int current = root->val;
        buildNodes(root->left, nodes);
        nodes.push_back(current);
        buildNodes(root->right, nodes);
    }


    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        buildNodes(root, nodes);
        return nodes[k-1];
    }
};
