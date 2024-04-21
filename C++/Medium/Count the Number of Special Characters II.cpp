
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> map;
        for (char c : word) {
            if (c < 'a') { // uppercase
                if (map[c + 32] == 1) map[c + 32] = 2; // correct order so far
                if (map[c + 32] == 0)map[c + 32] = -1; // not special
            }
            else { // lowercase
                if (map[c] == 2) map[c] = -1; // not special
                else if (map[c] == 1 || map[c] == 0)map[c] = 1;
            }
        }
        int res = 0;
        for (auto i = map.begin(); i != map.end(); i++) {
            cout << i->first << ": " << i->second << " ";
            if (i->second == 2) {
                res++;
            }
        }
        return res;
    }
};