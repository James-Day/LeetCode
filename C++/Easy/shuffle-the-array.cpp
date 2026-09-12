class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        auto half_size = nums.begin() + (nums.size() / 2);
        vector<int> leftCpy(nums.begin(), half_size);
        for (int i = 0; i + 1 < nums.size(); i+=2){
            nums[i] = leftCpy[i/2];
            nums[i + 1] = nums[n + (i / 2)];
        }
        return nums;
    }
};


//      1,2,3,4,5,6,7,8,9,10

//      1,6,2,7,3,8,4,9,10