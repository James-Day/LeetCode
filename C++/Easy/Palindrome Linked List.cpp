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
/*class Solution { //I'll definitally come back and do a proper solution, a stack should probablly be used instead of a vector as well. //can be done in O(1) space by reversing the second half of the list
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
};*/

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
class Solution { //reverse the second half of the list so that it is O(n) time and O(1) space! :)
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int size = 0;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            size++;
        }
        ListNode* rev = reverse(slow);

        while (rev != nullptr) {
            if (head->val != rev->val) {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};