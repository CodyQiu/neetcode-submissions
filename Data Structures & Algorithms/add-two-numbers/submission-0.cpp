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
        int carry = 0;
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        while (first != nullptr || second != nullptr) {
            if (first == nullptr) {
                ListNode* res = new ListNode((carry + second->val)%10);
                if (carry + second->val >= 10) carry = 1;
                else carry = 0;
                temp->next = res;
                temp = temp->next;
                second = second->next;
            } else if (second == nullptr) {
                ListNode* res = new ListNode((carry + first->val)%10);
                if (carry + first->val >= 10) carry = 1;
                else carry = 0;
                temp->next = res;
                temp = temp->next;
                first = first->next;
            } else {
                ListNode* res = new ListNode((carry + second->val + first->val)%10);
                if (carry + second->val + first->val >= 10) carry = 1;
                else carry = 0;
                temp->next = res;
                temp = temp->next;
                first = first->next;
                second = second->next;
            }
        }
        if (carry == 1) {
            ListNode* res = new ListNode(1);
            temp->next = res;
        }
        ListNode* final = head->next;
        return final;
    }
};
