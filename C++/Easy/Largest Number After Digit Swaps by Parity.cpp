class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd, even, copy;
        while (num > 0) {
            int digit = num % 10;
            if (digit % 2 == 0) {
                even.push_back(digit);
            }
            else {
                odd.push_back(digit);
            }
            copy.push_back(digit);
            num /= 10;
        }
        sort(odd.begin(), odd.end(), greater<int>()); //could also use priority queue
        sort(even.begin(), even.end(), greater<int>());
        int evenIndex = 0;
        int oddIndex = 0;
        int ans = 0;
        for (int i = 0; i < copy.size(); i++) {
            if (copy[copy.size() - 1 - i] % 2 == 0) { //try reversing instead
                ans = (ans * 10) + even[evenIndex];
                evenIndex++;
            }
            else {
                ans = (ans * 10) + odd[oddIndex];
                oddIndex++;
            }
        }
        return ans;
    }
};