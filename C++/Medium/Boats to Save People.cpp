//pair heaviest and lightest person if possible.
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int i = 0;
        int j = people.size() - 1;
        int ans = 0;
        while (i <= j) {
            if (people[i] + people[j] > limit) {
                i++;
                ans++;
            }
            else {
                i++;
                j--;
                ans++;
            }
        }
        return ans;
    }
};