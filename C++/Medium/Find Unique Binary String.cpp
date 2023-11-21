#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> seen;
        for (int i = 0; i < nums.size(); i++) {
            seen.insert(nums[i]);
        }

        int n = nums[0].length();
        string begin = "";
        for (int i = 0; i < n; i++) {
            begin.append("0"); //better way?
        }
        return backtrack(0, begin, n, seen);


    }
    string backtrack(int height, string cur, int& n, unordered_set<string>& seen) {
        if (height == n) { // base case
            if (!seen.contains(cur)) {
                return cur; //string does not exist in seen
            }
            return ""; // string was found in seen
        }

        string res = backtrack(height + 1, cur, n, seen);
        if (res != "") return res;
        cur[height] = '1';
        res = backtrack(height + 1, cur, n, seen);
        return res;
    }
};