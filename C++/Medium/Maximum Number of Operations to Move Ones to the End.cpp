/*
Intuition
Think backwards, take the example: "100110"
the first one from the back will move one time, 
the second one from the back, will move one time. 
The third one from the back will move twice. 
The number of times that each one moves is dependent on the number of gaps in front of it. 
So if we think backwards we can count the number of gaps seen so far, 
and for each one we see we know it will move that many times(number of gaps).
*/

class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int countGaps = (s[s.size() - 1] == '0');
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == '0' && s[i + 1] == '1') {
                countGaps++;
            }
            else if (s[i] == '1') {
                ans += countGaps;
            }
        }
        return ans;
    }
};