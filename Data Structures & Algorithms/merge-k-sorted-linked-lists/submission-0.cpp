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
    ListNode* merge(ListNode*& v1, ListNode*& v2) {
        if (v1 == nullptr) return v2;
        else if (v2 == nullptr) return v1;
        ListNode* first = v1;
        ListNode* second = v2;
        ListNode* head;
        if (v1->val < v2->val) {
            head = first;
            first = first->next;
        } else {
            head = second;
            second = second->next;
        }
        ListNode* curr = head;
        while (first != nullptr || second != nullptr) {
            if (first != nullptr && second != nullptr) {
                if (first->val < second->val) {
                    curr->next = first;
                    curr = curr->next;
                    first = first->next;
                } else {
                    curr->next = second;
                    curr = curr->next;
                    second = second->next;
                }
            } else if (first != nullptr && second == nullptr) {
                curr->next = first;
                curr = curr->next;
                first = first->next;
            } else {
                curr->next = second;
                curr = curr->next;
                second = second->next;
            }
        }
        return head;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        for (int i = 0; i < lists.size() - 1; i++) {
            ListNode* temp = merge(lists[i], lists[i+1]);
            lists[i+1] = temp;
        }
        return lists[lists.size() - 1];
        
    }
};
