#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        struct day {
            int temp;
            int i;
        };

        vector<day> stack;
        vector<int> ans(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && stack.back().temp < temperatures[i]) {
                ans[stack.back().i] = i - stack.back().i;
                stack.pop_back();
            }
            day newDay;
            newDay.temp = temperatures[i];
            newDay.i = i;
            stack.push_back(newDay);
        }
        return ans;
    }
};