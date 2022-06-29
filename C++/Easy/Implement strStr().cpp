class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){return 0;}
        
        for(int i =0; i < haystack.size(); i++){
                for(int j =i; (j < haystack.size() && j-i < needle.size()) && haystack.at(j) == needle.at(j-i); j++){
                    if(j-i == needle.size() -1){return i;}
                }
        }
        return -1;
    }
};