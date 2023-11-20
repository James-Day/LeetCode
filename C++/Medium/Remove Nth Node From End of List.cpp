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
        ListNode* right = head;
        ListNode* left = head;

        for (int i = 0; i < n; i++) {
            right = right->next;
        }
        if (right == nullptr) {
            return left->next; ///would obviously need to delete original node
        }
        while (right->next) {
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;//would need to delete left->next
        return head;
    }
};