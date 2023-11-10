#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> map;
        unordered_map<char, char> map2;

        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) == map.end() && map2.find(t[i]) == map2.end()) {
                map[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else if (map[s[i]] != t[i] //|| map2[t[i]] != s[i]
                ) {
                return false;
            }
        }
        return true;
    }
};