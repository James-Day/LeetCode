#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;

        }
        for (auto i : map) {
            if (i.second == 1)
                return i.first;
        }
        return 0;
    }
};