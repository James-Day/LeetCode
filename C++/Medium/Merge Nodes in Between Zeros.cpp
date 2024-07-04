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

//editing the given list is faster.
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* start = head;
        while (start) {
            ListNode* end = start;
            int sum = 0;
            while (end->val != 0) {
                sum += end->val;
                end = end->next;
            }
            start->val = sum;
            start->next = end->next;
            start = end->next;
        }
        return head;
    }
};


// original solution creating a new list.
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* newList = new ListNode();
        ListNode* newListCur = newList;
        while (cur != nullptr) {
            int nextNodeVal = 0;
            while (cur->val != 0) {
                nextNodeVal += cur->val;
                cur = cur->next;
            }
            newListCur->next = new ListNode(nextNodeVal);
            newListCur = newListCur->next;
            cur = cur->next;
        }
        return newList->next;
    }
};