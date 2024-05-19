//best solution, just count same pariotys as you iterate through the array.
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> wrongCount(1, 0);
        int sameParityCount = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] % 2 == nums[i] % 2) sameParityCount++;
            wrongCount.push_back(sameParityCount);
        }
        for (vector<int>& vec : queries) {
            ans.push_back(wrongCount[vec[0]] == wrongCount[vec[1]]);
        }
        return ans;
    }
};

//a bit better solution that skips any already calculated 
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        unordered_map<int, int> dp;
        for (int i = 0; i < queries.size(); i++) {
            done = false;
            for (int j = queries[i][0]; j < queries[i][1]; j++) {
                if (dp.count(j) != 0) {
                    //skip numbers in dp
                    j = dp[j];
                }
                else if (nums[j] % 2 != nums[j + 1] % 2) {
                    dp[queries[i][0]] = j;
                }
                else {
                    ans.push_back(false);
                    break;
                }
            }
            if (!done)ans.push_back(true);
        }
        return ans;

    }
};
//initial solution using ranges.
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, int>> badIndexRanges; //from, to
        for (int i = 1; i < nums.size(); i++) {
            int start = i - 1;
            while (i < nums.size() && nums[i - 1] % 2 == nums[i] % 2) {
                i++;
            }
            if (start != i - 1) {
                badIndexRanges.push_back({ start, i - 1 });
            }
        }
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            bool queryAnswer = true;
            if (start == end) {
                ans.push_back(true);
                continue;
            }
            for (int j = 0; j < badIndexRanges.size(); j++) {
                if (start < badIndexRanges[j].second && end > badIndexRanges[j].first) {
                    queryAnswer = false;
                    break;
                }
            }
            ans.push_back(queryAnswer);
        }
        return ans;
    }
};