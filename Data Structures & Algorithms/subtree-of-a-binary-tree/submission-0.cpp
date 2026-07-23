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

    bool isEqual(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        else if ((root1 != nullptr && root2 == nullptr) || (root1 == nullptr && root2 != nullptr)) return false;
        if (root1->val != root2->val) return false;
        
        return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot != nullptr) return false;
        bool curr = isEqual(root, subRoot);
        if (curr) return true;
        else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }

    }
};
