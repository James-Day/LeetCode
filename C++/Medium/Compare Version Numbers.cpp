//a bit better on memory, as the numbers are stored a bit smaller. and stoi and substr don't have to be used.
int compareVersion(string version1, string version2) {
    int i = 0;
    int j = 0;
    int n1 = version1.size();
    int n2 = version2.size();

    int num1 = 0;
    int num2 = 0;
    while (i < n1 || j < n2)
    {
        while (i < n1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        while (j < n2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');;
            j++;
        }

        if (num1 > num2) return 1;
        else if (num1 < num2) return -1;

        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }

    return 0;
}
/* my solution, has a bit high memory usage but still O(N) TC and O(N) space
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int previ = 0;
        int prevj = 0;
        while (i < version1.size() && j < version2.size()) {
            while (i < version1.size() && version1[i] != '.') {
                i++;
            }
            while (j < version2.size() && version2[j] != '.') {
                j++;
            }
            string v1 = version1.substr(previ, i - previ); //instead store directly as integer
            string v2 = version2.substr(prevj, j - prevj);
            if(stoi (v1) < stoi(v2)) return -1;
            if(stoi (v1) > stoi(v2)) return 1;
            ++i, ++j;
            previ = i, prevj = j;
        }
        while(i < version1.size()){
            if (version1[i] != '0' && version1[i] != '.')  return 1;
            i++;
        }
        while(j < version2.size()){
            if (version2[j] != '0' && version2[j] != '.')  return -1;
            j++;
        }
        return 0;
    }
};
*/