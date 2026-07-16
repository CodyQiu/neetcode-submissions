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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (l1 != nullptr || l2 != nullptr) {
            int value = curr->val;
            if (l1 != nullptr) value += l1->val;
            if (l2 != nullptr) value += l2->val;
            if (value > 9) {
                curr->val = value % 10;
                ListNode* temp = new ListNode(1);
                curr->next = temp;
            } else {
                curr->val = value;
                ListNode* temp = new ListNode(0);
                curr->next = temp;
            }
            prev = curr;
            curr = curr->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (curr->val == 0) prev->next = nullptr;
        return head;
    }
};
