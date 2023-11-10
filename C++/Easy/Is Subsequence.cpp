#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()) return false; //Quick check to speed up funciton

        int subSeqCount = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[subSeqCount]) {
                subSeqCount++;
            }
        }
        return subSeqCount == s.length();
    }
};