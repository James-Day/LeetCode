#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> mapS;
        unordered_map<int, int> mapT;

        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            mapS[s[i]]++;
            mapT[t[i]]++;
        }

        return mapT == mapS;

    }
};