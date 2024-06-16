class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        unordered_map<int, long long> mod;
        for (int i = 0; i < hours.size(); i++) {
            hours[i] = hours[i] % 24;
            mod[hours[i]]++;
        }
        for (int i = 0; i <= 12; i++) {
            if (i == ((24 - i) % 24)) { //0 or 12
                ans += (mod[i] * (mod[i] - 1)) / 2;
            }
            else {
                ans += mod[i] * mod[(24 - i) % 24];
            }
        }
        return ans;
    }
};