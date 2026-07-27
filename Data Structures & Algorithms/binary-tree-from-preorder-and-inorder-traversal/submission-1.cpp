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

    TreeNode* buildHalf(vector<int>& preorder, TreeNode* root, unordered_map<int, int>& index, int left, int right) {
        if (left == right) return nullptr;
        root = new TreeNode(preorder[0]);
        preorder.erase(preorder.begin());
        //vector<int> left(inorder.begin(), inorder.begin() + index[root->val]);
        //vector<int> right(inorder.begin() + index[root->val] + 1, inorder.end());
        root->left = buildHalf(preorder, nullptr, index, left, index[root->val]);
        root->right = buildHalf(preorder, nullptr, index, index[root->val] + 1, right);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildHalf(preorder, nullptr, index, 0, index.size());
    }
};
