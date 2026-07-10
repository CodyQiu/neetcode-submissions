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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        ListNode* curr;
        ListNode* other;
        ListNode* final;
        if (list1->val <= list2->val) {
            curr = list1;
            other = list2;
            final = curr;
        } else {
            other = list1;
            curr = list2;
            final = curr;
        }
        while (curr != nullptr) {
            if (curr->next == nullptr) {
                curr->next = other;
                break;
            } 
            if (curr->next->val <= other->val) {
                curr = curr->next;
            } else {
                ListNode* tmp = curr->next;
                curr->next = other;
                other = tmp;
                curr = curr->next;
            }
        }
        return final;
    }
};
