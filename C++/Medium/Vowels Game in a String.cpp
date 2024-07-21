
/*
Intuition
If there are an odd number of vowels, Alice simply removes the entire string and wins.
if there are an even number of vowels, there are two possibilities, 
ex: "caceeac", in this case (greedy)Alice removes all but one vowel ("ca"),
bob removes some amount of consonants("a") and then Alice removes everything leftover in the string and wins.
ex2:"ae", in this case, Alice removes one vowel, there are no consonants to remove, and not enough vowels,
so Bob cannot play, and Alice wins!. Notice in all cases, if there is a vowel, Alice will win with correct play!.

Approach
Simply ittereate over the string, if we see a vowel then return true because 
we proved that Alice always wins with 1 or more vowels!
*/
class Solution {
public:
    bool doesAliceWin(string s) {
        vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < vowels.size(); j++) {
                if (vowels[j] == s[i]) {
                    return true;
                }
            }
        }
        return false;
    }
};