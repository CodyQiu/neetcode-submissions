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
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* head;
        if (list1->val < list2->val) {
            head = list1;
            curr = list1;
            first = first->next;
        } else {
            curr = list2;
            head = list2;
            second = second->next;
        }
        while (first != nullptr || second != nullptr) {
            if (first == nullptr && second != nullptr) {
                curr->next = second;
                curr = curr->next;
                second = second->next;
            } else if (first != nullptr && second == nullptr) {
                curr->next = first;
                curr = curr->next;
                first = first->next;
            } else if (first != nullptr && second != nullptr) {
                if (first->val < second->val) {
                    curr->next = first;
                    curr = curr->next;
                    first = first->next;
                } else {
                    curr->next = second;
                    curr = curr->next;
                    second = second->next;
                }
            }
        }
        return head;
    }
};
