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
        unordered_map<Node*, Node*> m;
        Node* curr = head;
        Node* rand = new Node(head->val);
        m[curr] = rand;
        Node* ptr = rand;
        curr = curr->next;
        while (curr != nullptr) {
            Node* temp = new Node(curr->val);
            ptr->next = temp;
            m[curr] = temp;
            ptr = temp;
            curr = curr->next;
        }
        curr = head;
        ptr = rand;
        while (curr != nullptr) {
            ptr->random = m[curr->random];
            ptr = ptr->next;
            curr = curr->next;
        }
        return rand;
    }
};
