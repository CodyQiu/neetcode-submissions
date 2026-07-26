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

    bool helper(TreeNode* root, int &smallRight, int &bigLeft) {
        if (root == nullptr) return true;
        if (root->left != nullptr && root->left->val >= root->val) return false;
        if (root->right != nullptr && root->right->val <= root->val) return false;
        bool final = helper(root->left, smallRight, bigLeft);
        int tempR = smallRight;
        int tempL = bigLeft;
        if (root->val <= tempL) return false;
        smallRight = INT_MAX;
        bigLeft = INT_MIN;
        final = final && helper(root->right, smallRight, bigLeft);
        if (root->right != nullptr) smallRight = min(smallRight, root->right->val);
        if (root->left != nullptr) bigLeft = max(bigLeft, root->left->val);
        if (!final) return false;
        if (smallRight <= root->val) return false;
        smallRight = min(tempR, smallRight);
        smallRight = min(smallRight, root->val);
        bigLeft = max(tempL, bigLeft);
        bigLeft = max(bigLeft, root->val);
        return true;
    }

    bool isValidBST(TreeNode* root) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        return helper(root, smallest, largest);
    }
};
