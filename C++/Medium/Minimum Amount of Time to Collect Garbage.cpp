#include <vector>
#include <iostream>

class Solution {
public:
    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
        int ans = 0;
        for (int i = 0; i < garbage.size(); i++) { // could move this to other for loop
            ans += garbage[i].length();
        }
        int metal = -1;
        int paper = -1;
        int glass = -1;
        for (int i = garbage.size() - 1; i >= 0; i--) {
            if (metal == -1 && garbage[i].find('M') != std::string::npos) {
                metal = i;
            }
            if (glass == -1 && garbage[i].find('G') != std::string::npos) {
                glass = i;
            }
            if (paper == -1 && garbage[i].find('P') != std::string::npos) {
                paper = i;
            }
        }
        for (int i = 0; i < travel.size(); i++) {
            if (metal > i) ans += travel[i];
            if (paper > i) ans += travel[i];
            if (glass > i) ans += travel[i];
        }
        return ans;
    }
};