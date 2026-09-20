// Valid Mountain Array � condensed from 1 distinct accepted submission(s).

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        bool down = false;
        bool up = false;
        for(int i = 0 ; i < arr.size() - 1; i++){
            if(arr[i + 1] == arr[i]) return false;
            if(down && arr[i + 1] > arr[i]) return false;
            if(arr[i + 1] > arr[i]) up = true;
            if(arr[i + 1] < arr[i]) down = true;
        }
        return down && up;
    }
};
