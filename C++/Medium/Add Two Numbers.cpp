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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* finalResult= new ListNode(0,nullptr); //dummy head of list
        ListNode* finalIterator = finalResult;
        int carry =0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(l1 != nullptr || l2 != nullptr){
         if(l1 != nullptr){
            finalIterator->val =  l1->val;
            l1 = l1->next;    
         }
        if(l2 != nullptr) { 
            finalIterator->val += l2->val;
            l2 = l2->next;
            }
        finalIterator->val += carry;
            if(finalIterator->val >=10){
                carry =1;
                finalIterator->val -=10;
            }
            else{
                carry =0;
            }
            if(l1 != nullptr || l2 != nullptr){
            finalIterator->next = new ListNode(0,nullptr);
            finalIterator = finalIterator->next;
            }
        }
        //check for appending a 1
        if(carry >= 1){
        finalIterator->next = new ListNode(1,nullptr);
        }
        return finalResult;
    }
};