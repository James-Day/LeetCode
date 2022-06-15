
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* copy = head;
        ListNode* returnCopy = head;
        ListNode* returnCopy2 = head;
        while (head != nullptr) {
            head = head->next;
            size++;
        }
        int nodeToDelete = size - n;
        while (nodeToDelete > 0) {
            copy = copy->next;
            nodeToDelete--;
        }

        if (copy->next != nullptr) {
            copy->val = copy->next->val;
            copy->next = copy->next->next;
        }
        else {
            size--;
            if (size == 0) {
                return nullptr;
            }
            while (returnCopy2->next != copy) {
                returnCopy2 = returnCopy2->next;
            }
            returnCopy2->next = nullptr;
            delete copy;
        }
        return returnCopy;
    }
};