// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
#include <vector>
#include <string>
#include <climits>
using namespace std;

// O(n) index-building solution
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<int> maxInd(26, INT_MIN);
        vector<int> minInd(26, INT_MAX);

        for(int i = 0; i < s.size(); i++){
            int charIndex = s[i] - 'a';
            maxInd[charIndex] = max(maxInd[charIndex], i);
            minInd[charIndex] = min(minInd[charIndex], i);
        }

        for(int i = 0; i < 26; i++){
            //if the char isnt in string twice skip
            if(maxInd[i] == INT_MIN || minInd[i] == INT_MAX) continue; 
            bool uniqueCharsBetween[26] = {}; //faster than hash set for chars in this instance
            for(int j = minInd[i] + 1; j < maxInd[i]; j++){
                uniqueCharsBetween[s[j] - 'a'] = true;
            }
            for(bool b : uniqueCharsBetween){
                ans += b;
            }
        }
        return ans;
    }
};

// O(26*n) scan solution - worse due to repeated full-string scans per character
/*
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {

            int first = -1;
            int last = -1;

            // Find first and last occurrence
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ch) {
                    if (first == -1)
                        first = i;

                    last = i;
                }
            }

            // Character doesn't occur at least twice
            if (first == -1 || first == last)
                continue;

            // Count unique characters between first and last
            bool seen[26] = {false};

            for (int i = first + 1; i < last; i++) {
                seen[s[i] - 'a'] = true;
            }

            for (int i = 0; i < 26; i++) {
                if (seen[i])
                    ans++;
            }
        }

        return ans;
    }
};
*/
