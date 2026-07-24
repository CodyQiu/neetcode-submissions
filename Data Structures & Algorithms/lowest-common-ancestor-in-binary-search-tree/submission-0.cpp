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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Locate p
        string sp = "";
        TreeNode *curr = root;
        while (true) {
            if (curr->val > p->val) {
                curr = curr->left;
                sp += "L";
            }
            else if (curr->val < p->val) {
                curr = curr->right;
                sp += "R";
            } else {
                break;
            }
        }
        // Locate q
        string sq = "";
        curr = root;
        while (true) {
            if (curr->val > q->val) {
                curr = curr->left;
                sq += "L";
            }
            else if (curr->val < q->val) {
                curr = curr->right;
                sq += "R";
            } else {
                break;
            }
        }
        curr = root;
        for (int i = 0; i < min(sp.size(),sq.size()); i++) {
            if (sq[i] != sp[i]) break;
            if (sq[i] == 'L') curr = curr->left;
            else curr = curr->right;
        }
        return curr;
    }
};
