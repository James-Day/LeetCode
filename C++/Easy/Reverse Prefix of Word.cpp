//"don't reinvent the wheel solution"
class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int j = 0; j < word.size(); j++) {
            if (word[j] == ch) {
                reverse(word.begin(), word.begin() + j + 1);
                break;
            }
        }
        return word;
    }
};
//original solution
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = 0;
        for (; j < word.size(); j++) {
            if (word[j] == ch)
                break;
        }
        if (j == word.size()) return word;
        int i = 0;
        while (i < j) {
            char copy = word[i];
            word[i] = word[j];
            word[j] = copy;
            i++;
            j--;
        }
        return word;
    }
};