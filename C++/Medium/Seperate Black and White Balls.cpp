#include <iostream>
using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        int add = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') add++;
            else {
                count += add;
            }
        }
        return count;

    }
};