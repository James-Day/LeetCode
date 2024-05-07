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
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        bool carry = false;
        ListNode* cur = head;
        while (cur) {
            int timesTwo = cur->val * 2;
            cur->val = ((timesTwo) % 10) + carry;
            carry = (timesTwo)+carry >= 10;
            cur = cur->next;
        }
        head = reverse(head);
        if (carry) {
            ListNode* carryNode = new ListNode(1, head);
            return carryNode;
        }
        return head;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = head;
        ListNode* prev = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};