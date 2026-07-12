/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (slow != nullptr && fast != nullptr) {
            slow = slow->next;
            if (slow == nullptr) return false;
            fast = fast->next;
            if (fast == nullptr) return false;
            fast = fast->next;
            if (fast == nullptr) return false;
            if (fast == slow) return true;
        }
        return false;
    }
};
