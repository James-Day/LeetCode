#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int l = 0;
        int r = 0;
        int lchar = 0;
        int rchar = 0;

        while (true)
        {

            if (l >= word1.size() || r >= word2.size())
            {
                return false;
            }

            if (word1[l][lchar] == word2[r][rchar])
            {
                lchar++;
                rchar++;
                if (lchar >= word1[l].size())
                {
                    lchar = 0;
                    l++;
                }
                if (rchar >= word2[r].size())
                {
                    rchar = 0;
                    r++;
                }
            }
            else
            {
                return false;
            }

            if (l == word1.size() && r == word2.size())
            {
                return true;
            }
        }
        return true; // should never run
    }
};