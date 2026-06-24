/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        vector<Node*> nodes;
        vector<pair<Node*, int>> nodeswithR;
        unordered_map<Node*, int> m;
        vector<Node*> final;
        Node* curr = head;
        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        for (int i = 0; i < nodes.size(); i++) {
            m[nodes[i]] = i;
        }
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->random != nullptr) {
                nodeswithR.push_back({nodes[i], m[nodes[i]->random]});
            } else {
                nodeswithR.push_back({nodes[i], -1});
            }
        }
        for (int i = 0; i < nodes.size(); i++) {
            Node* temp = new Node(nodes[i]->val);
            final.push_back(temp);
        }
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->random != nullptr) {
                final[i]->random = final[nodeswithR[i].second];
            } else {
                final[i]->random = nullptr;
            }
            if (i <= nodes.size() - 2) {
                final[i]->next = final[i+1];
            } else {
                final[i]->next = nullptr;
            }
        }
        return final[0];
        }
};
