//better solution with an array since we know the number of elements to be tracked in the map.
class Solution {
public:
    int firstUniqChar(string s) {
        int alphabetCount[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            alphabetCount[s.at(i) - 'a']++;
        }
        for (int j = 0; j < s.size(); j++) {
            if (alphabetCount[s.at(j) - 'a'] < 2) {
                return j;
            }
        }
        return -1;
    }
};

/*
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char,int> lookup;

        for(int i =0; i < s.size(); i++){
            lookup[s.at(i)]++;
        }

        for(int j =0; j < s.size(); j++){
            if(lookup[s.at(j)] < 2){
                return j;
            }
        }
        return -1;
    }
};*/