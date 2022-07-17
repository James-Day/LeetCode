/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * itr = head;
        vector<ListNode*> history;
        while(itr != nullptr){
            for(int i =0; i< history.size(); i++){
                if(history[i] == itr){return true;}
            }
            history.push_back(itr);
            itr = itr->next;
        }
        return false;
    }
};