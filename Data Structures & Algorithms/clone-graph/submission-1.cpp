/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_set<Node*> visited;
    unordered_map<Node*, Node*> copies;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if (visited.contains(node)) return copies[node];
        Node* curr = new Node(node->val);
        copies[node] = curr;
        visited.insert(node);
        for (auto& x: node->neighbors) {
            Node* temp = cloneGraph(x);
            curr->neighbors.push_back(temp);
        }
        return curr;
    }
};
