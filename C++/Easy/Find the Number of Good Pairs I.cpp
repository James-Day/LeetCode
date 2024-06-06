class Solution { //there is a faster solution check out part two of this question.
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = 0; j < nums1.size(); j++) {
                if (nums1[j] % (nums2[i] * k) == 0) ans++;
            }
        }
        return ans;
    }
};