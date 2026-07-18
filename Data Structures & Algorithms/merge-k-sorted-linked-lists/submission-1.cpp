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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        else if (lists.size() == 1 && lists[0] == nullptr) return nullptr;
        ListNode* head = new ListNode();
        ListNode* curr = head;
        ListNode* nextmin = lists[0];
        int index = 0;
        while (true) {
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) continue;
                else if (lists[i]->val < nextmin->val) {
                    nextmin = lists[i];
                    index = i;
                }
            }
            if (lists[index] != nullptr) lists[index] = lists[index]->next;
            curr->next = nextmin;
            curr = nextmin;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr) {
                    nextmin = lists[i];
                    index = i;
                    break;
                } else nextmin = nullptr;
            }
            if (nextmin == nullptr) break;
        }
        return head->next;
    }
};
