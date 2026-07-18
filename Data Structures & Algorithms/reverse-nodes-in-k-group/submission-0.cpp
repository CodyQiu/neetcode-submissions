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


    pair<ListNode*, ListNode*> reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* original = head;

        int size = 0;
        while (head != nullptr) {
            head = head->next;
            size++;
            if (size > k) break;
        }
        if (size < k) return {original, nullptr};
        head = original;

        for (int i = 0; i < k; i++) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return {prev, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* tailToHead = nullptr;
        ListNode* final = nullptr;
        int i = 0;
        for (i = 0; i < k - 1; i++) curr = curr->next;
        final = curr;
        // will do edge case later
        ListNode* tailPrevious = nullptr;
        ListNode* headCurrent;
        curr = head;
        int count = 0;
        while (true) {
            ListNode* temp = curr;
            pair<ListNode*, ListNode*> xx = reverse(curr, k);
            headCurrent = xx.first;
            if (tailPrevious != nullptr) tailPrevious->next = headCurrent;
            curr = xx.second;
            tailPrevious = temp;
            count++;
            if (curr == nullptr) break;
        }
        return final;
    }
};
