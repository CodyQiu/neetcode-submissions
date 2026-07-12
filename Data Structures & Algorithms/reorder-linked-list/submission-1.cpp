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
    void reorderList(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            size++;
            curr = curr->next;
        }
        int half = size % 2 == 0 ? size / 2 : size / 2 + 1;
        ListNode* split = head;
        ListNode* temp;
        for (int i = 0; i < half; i++) {
            if (i == half - 1) temp = split;
            split = split->next;
        }
        temp->next = nullptr;
        ListNode* prev = nullptr;
        curr = split;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr = head;
        while (curr != nullptr && prev != nullptr) {
            ListNode* temp1 = curr->next;
            ListNode* temp2 = prev->next;
            curr->next = prev;
            prev->next = temp1;
            curr = temp1;
            prev = temp2;
        }
    }
};
