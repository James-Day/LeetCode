class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long  ans = 0;
        unordered_map<int, int> freq; //can't use set because of duplicates
        for (int num : nums2) freq[num * k]++;
        for (int num : nums1) {
            int sqr = sqrt(num);
            for (int i = 1; i < sqr; i++) {
                if (num % i == 0) {
                    ans += freq[i];
                    ans += freq[num / i];
                }
            }
            if (num % sqr == 0) {
                ans += freq[sqr];
                if (num / sqr != sqr) {
                    ans += freq[num / sqr];
                }

            } //sqr is special case and don't want to double count it
        }
        return ans;
    }
};