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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            size++;
        }
        int index = size - n;
        curr = head;
        ListNode* prev = curr;
        for (int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == head) head = curr->next;
        delete curr;
        return head;
    }
};
