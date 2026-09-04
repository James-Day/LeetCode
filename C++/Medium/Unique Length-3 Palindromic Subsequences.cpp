// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
#include <vector>
#include <string>
#include <climits>
using namespace std;

// O(n) index-building solution - precomputes min/max indices in a single pass
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

// worse because of the use of a set for chars
/*
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
        
        unordered_set<char> uniqueCharsBetween;

        for(int i = 0; i < 26; i++){
            //if the char isnt in string twice skip
            if(maxInd[i] == INT_MIN || minInd[i] == INT_MAX) continue; 
            for(int j = minInd[i] + 1; j < maxInd[i]; j++){
                uniqueCharsBetween.insert(s[j]);
            }
            ans += uniqueCharsBetween.size();
            uniqueCharsBetween.clear();

        }
        return ans;
    }
};

*/
