class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int trueAns = 0;
        int redCopy = red;
        int blueCopy = blue;
        for (int j = 0; j < 2; j++) { //check blue first, then swap and check red first.
            if (j == 1) {
                blue = redCopy;
                red = blueCopy;
            }
            int a = 1;
            int b = 2;
            int ans = 0;
            for (int i = 0; red >= 0 && blue >= 0; i++) {
                blue -= a;
                if (blue >= 0) {
                    ans++;
                    red -= b;
                    if (red >= 0) {
                        ans++;
                    }
                }
                a += 2;
                b += 2;
            }
            trueAns = max(trueAns, ans);
        }
        return trueAns;
    }
};