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
        while (curr != nullptr) {
            curr = curr->next;
            size++;
        }
        curr = head;
        // Find middle of linked list
        for (int i = 0; i < size / 2; i++) {
            curr = curr->next;
        }
        ListNode* front2 = curr->next;
        curr->next = nullptr;
        // Reverse second half
        ListNode* rev = nullptr;
        curr = front2;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = rev;
            rev = curr;
            curr = temp;
        }
        // Merge linked lists head and rev
        curr = head;
        while (curr != nullptr && rev != nullptr) {
            ListNode* temp1 = curr->next;
            ListNode* temp2 = rev->next;
            curr->next = rev;
            rev->next = temp1;
            curr = temp1;
            rev = temp2;
        }
    }
};
