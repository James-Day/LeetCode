// Find All Numbers Disappeared in an Array — condensed from 2 distinct approaches.
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};

// Archived alternative: cyclic sort
// Not compiled; retained for comparison.
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int index = 0;
//         while (index < nums.size()) {
//             int correctIndex = nums[index] - 1;
//             if (nums[index] != nums[correctIndex]) {
//                 swap(nums[index], nums[correctIndex]);
//             } else {
//                 index++;
//             }
//         }
//
//         vector<int> missing;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] != i + 1) missing.push_back(i + 1);
//         }
//         return missing;
//     }
// };