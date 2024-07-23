class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&](int num1, int num2) {
            if (freq[num1] == freq[num2]) return num1 > num2;
            return freq[num1] < freq[num2];
            });
        return nums;
    }
};