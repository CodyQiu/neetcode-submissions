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
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ptr2 = ptr2->next;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1 == ptr2) return true;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr2 == nullptr) return false;
            ptr2 = ptr2->next;
        }
        return false;
    }
};
