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
/*
essentially same solution O(N) time, O(N) Space
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> mapping;
        unordered_map<char, char> backwardsMapping;
        for(int i = 0; i < s.size(); i++){
            if(mapping.contains(s[i]) && mapping[s[i]] != t[i]) return false;
            if(backwardsMapping.contains(t[i]) && backwardsMapping[t[i]] != s[i]) return false;

            mapping[s[i]] = t[i];
            backwardsMapping[t[i]] = s[i];
        }
        return true;
    }
};
*/