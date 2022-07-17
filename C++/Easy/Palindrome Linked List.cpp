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
class Solution { //I'll definitally come back and do a proper solution, a stack should probablly be used instead of a vector as well. //can be done in O(1) space by reversing the second half of the list
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int> firsthalf;
        ListNode* itr = head;
        int size =0;
        
        while(itr != nullptr){
            size++;
            itr = itr->next;
        }
        
        itr = head;
        for(int i =0; i < size/2; i++){
             firsthalf.push_back(itr->val);
             itr = itr->next;
        }
        if(size%2 == 1){
             itr = itr->next;
        }
        while(itr != nullptr){
            if(firsthalf.back() != itr->val){
                return false;
            }
            firsthalf.pop_back();
            itr = itr->next;
        }
        return true;
        
    }
};