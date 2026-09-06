class Solution {
public:
    int countRotations(string s, int k) {
        int circCount = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == s[(i+1) % s.size()]){
                circCount ++;
            }
        }
        if(circCount == k){
            return s.size() - circCount;
        }
        if(circCount - 1 == k){
            return circCount;
        }
        return 0;
    }
};