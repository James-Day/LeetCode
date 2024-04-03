//O(N + M) Time. Using set has lookups that take O(1) so overall performance can be reduce from O(N * M) to O(N + M) 
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> findJewels;
        for (char jewel : jewels) {
            findJewels.insert(jewel);
        }
        int count = 0;
        for (char stone : stones) {
            if (findJewels.contains(stone)) count++;
        }
        return count;
    }
};