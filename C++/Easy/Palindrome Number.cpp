

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        long backwards = 0;
        int copy = x;
        while (copy > 0){
            backwards = (backwards * 10) + copy % 10;
            copy /= 10;
        }
        return x == backwards;

    }
};
/*
if the input was already a long long, you couldn't just rely on a bigger data type, so heres the solution in that case
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        int backwards = 0;
        int copy = x;
        int rem = -1;
        while (copy > 0){
            if (copy < 10 && x > 1000000000){
                rem = copy % 10;
            }
            else{
                backwards = (backwards * 10) + copy % 10;
            }
            copy /= 10;
        }
        if(rem != -1 && rem == x % 10){
            x /= 10;
            return x == backwards;
        }
        return x == backwards;

    }
};
*/