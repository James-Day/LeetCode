//O(N^3) Not optimal, but this was my initial solution for contest.
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0;
        int sum2 = 0;
        int size = nums2.size();
        int ans = INT_MAX;
        for (int i = 0; i < nums1.size(); i++) {
            sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++) {
            sum2 += nums2[i];
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                if ((sum2 - sum1 + nums1[i] + nums1[j]) % size == 0) {
                    unordered_map<int, int> count1;
                    unordered_map<int, int> count2;
                    int potAnswer = (sum2 - sum1 + nums1[i] + nums1[j]) / size;
                    for (int k = 0; k < nums1.size(); k++) {

                        if (k != i && k != j) {
                            count1[nums1[k] + potAnswer]++;
                        }
                    }
                    for (int k = 0; k < size; k++) {
                        count2[nums2[k]]++;
                    }
                    if (count1 == count2) {
                        ans = min(ans, potAnswer);
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};