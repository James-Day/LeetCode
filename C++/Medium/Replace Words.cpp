//Solution without TRIE, may also be able to use string stream to avoid so much copying
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> seen;
        string cur = "";
        string ans = "";
        for (int i = 0; i < dictionary.size(); i++) {
            seen.insert(dictionary[i]);
        }
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ') cur += sentence[i];
            if (seen.contains(cur)) {
                ans += cur + " ";
                while (i < sentence.length() && sentence[i] != ' ') i++;
                cur = "";
            }
            else if (sentence[i] == ' ') {
                ans += cur + " ";
                cur = "";
            }
        }
        if (cur != "") ans += cur + " ";
        return ans.erase(ans.size() - 1);
    }
};