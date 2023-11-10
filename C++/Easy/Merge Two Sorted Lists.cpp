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

//more concise solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        while (list1 && list2) {
            ListNode* next = (list1->val < list2->val) ? list1 : list2;
            cur->next = next;
            cur = cur->next;
            (next == list1) ? list1 = list1->next : list2 = list2->next;
        }
        cur->next = (list1) ? list1 : list2;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};