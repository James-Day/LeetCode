class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> s;
        int res = 0;
        for (char c : word) s.insert(c);
        for (int i = 0; i < 26; i++) {
            if (s.find(i + 'a') != s.end() && s.find(i + 'A') != s.end()) {
                res++;
            }
        }
        return res;
    }
};

/* Initial soltiuon: uses a bit more memory than needed.
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lowerCase;
        unordered_set<char> upperCase;
        for (char character : word) {
            if (character < 'a') { // uppercase
                upperCase.insert(character);
            }
            else {
                lowerCase.insert(character);
            }
        }
        int sol = 0;
        for (auto i = lowerCase.begin(); i != lowerCase.end(); i++) {
            if (upperCase.contains(*i - 32)) sol++;
        }
        return sol;
    }
};*/