class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = 0;
        bool deleted = false;
        while(right < nums.size()){
            if(deleted){
                nums[left] = nums[right];
            }
            if(nums[right] == val){
                deleted = true;
                left--;
            }
            left++;
            right++;
        }
        //if you'd like to fix the vector
        //nums.erase(...)
        return left;
    }
};