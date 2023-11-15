/
 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


//Basically just reverse second half of the list and then merge.
 
class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode* cur = head;
        int length = 0;
        while (cur) {
            length++;
            cur = cur->next;
        }
        if (length == 1) {
            return;
        }
        cur = head;
        for (int i = 0; i < length / 2; i++) {
            if (i + 1 >= length / 2) {
                ListNode* temp = cur->next;
                cur->next = nullptr;
                cur = temp;
                break;
            }
            cur = cur->next;
        }
        cur = reverse(cur);
        ListNode* begin = head;
        ListNode* temp = nullptr;
        while (cur || begin) {
            if (begin) {
                temp = begin->next;
                begin->next = cur;
                begin = temp;
            }
            if (begin) {
                temp = cur->next;
                cur->next = begin;
                cur = temp;
            }
            else break;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }


};