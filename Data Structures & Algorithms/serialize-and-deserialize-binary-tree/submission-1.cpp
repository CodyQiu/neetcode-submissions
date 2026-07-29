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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s = "";
        if (root != nullptr) q.push(root);
        else return s;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp != nullptr) s += to_string(temp->val) + ',';
            else s += "n,";
            if (temp != nullptr) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s.erase(s.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q;
        if (data.size() == 0) return nullptr;
        char delimiter = ',';
        vector<string> result;
        stringstream ss(data);
        string token;
        while (getline(ss, token, delimiter)) result.push_back(token);
        TreeNode* head = new TreeNode(stoi(result[0]));
        q.push(head);
        int index = 1;
        while (index < result.size()) {
            TreeNode* temp = q.front();
            q.pop();
            if (result[index] != "n") {
                TreeNode* l = new TreeNode(stoi(result[index]));
                temp->left = l;
                q.push(l);
            } else temp->left = nullptr;
            index++;
            if (result[index] != "n") {
                TreeNode* r = new TreeNode(stoi(result[index]));
                temp->right = r;
                q.push(r);
            } else temp->right = nullptr;
            index++;
        }
        return head;
    }
};
