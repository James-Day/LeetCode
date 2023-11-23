#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for (int i = 0; i < l.size(); i++) {

            if (r[i] - l[i] < 2) {
                ans.push_back(true);
                continue;
            }
            vector<int> copy(nums.begin() + l[i], nums.begin() + r[i] + 1);

            sort(copy.begin(), copy.end());

            bool cur = true;
            int areth = copy[1] - copy[0];
            for (int j = 1; j < copy.size() - 1; j++) {
                if (copy[j + 1] - copy[j] != areth) {
                    cur = false;
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};