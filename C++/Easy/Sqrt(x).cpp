/* Given a non-negative integer x,
 return the square root of x rounded down to the nearest integer. 
 The returned integer should be non-negative as well. */
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        int high = x;
        int low = 1;
        int mid = 0;
        while (low <= high){


            mid = low + (high - low) /2;
            long long square = static_cast<long long>(mid) * mid;
            if(square > x){
                high = mid -1;
            }
            else if (square == x) return mid;
            else {
                low = mid + 1;
            }
        }
        return high;
    }
};