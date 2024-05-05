class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
        bool consonant = false;
        bool vowelFound = false;
        for (char c : word) {
            if (!isalnum(c)) return false;
            if (isalpha(c)) {
                bool isVowel = false;
                for (char vowel : vowels) {
                    if (vowel == tolower(c)) {
                        vowelFound = true;
                        isVowel = true;
                    }
                }
                if (!isVowel) consonant = true;
            }
        }
        return consonant && vowelFound;
    }
};