#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <regex>

using namespace std;

struct cardToNum {
    char c;
    int num;
};

vector<string> customSplit(string input, char delimiter) {
    vector<string> res;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= input.size(); i++) {
        if (input[i] == delimiter || i == input.size()) {
            endIndex = i;
            string temp;
            temp.append(input, startIndex, endIndex - startIndex);
            res.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return res;
}

vector<string> removeSpaces(vector<string>& input) {
    vector<string> res;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != "") {
            res.push_back(input[i]);
        }
    }
    return res;
}

int recursion(string str, vector<int>& groups) {
    bool qsLeft = false;
    int index = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '?') {
            qsLeft = true;
            index = i;
            break;
        }
    }
    if (!qsLeft) {
        int j = 0;
        int consecutive = 0;
        for (int i = 0; i < groups.size(); i++) {
            while (j < str.size()&& str[j] != '#') {
                j++;
            }
            while ( j < str.size() && str[j] != '.') {
                consecutive++;
                j++;
            }
            if (consecutive != groups[i]) {
                return 0;
            }
            consecutive = 0;
        }
        while (j < str.size()) {
            if (str[j] == '#') return 0;
            j++;
        }
        return 1;
    }
    //if already invalid stop
    int consec = 0;
    int k = 0;
    for (int i = 0; i < groups.size(); i++) {
        if (str[k] == '?') {
            break;
        }
        while (k < str.size() && str[k] != '#') {
            if (str[k] == '?') {
                break;
            }
            k++;
        }
        while (k < str.size() && str[k] != '.') {
            if (str[k] == '?') {
                break;
            }
            consec++;
            k++;
        }
        if (str[k] == '?') {
            break;
        }
        if (consec != groups[i]) {
            return 0;
        }

        consec = 0;
    }

    int total = 0;

    for (int i = 0; i < groups.size(); i++) {
        total += groups[i];
    }
   
    if (str.length() < total + groups.size() - 1 ) {
        return 0;
    }



    str[index] = '.';
    int arrangements = recursion(str, groups); // make .
    str[index] = '#';
    int arrangements2 = recursion(str, groups); // make #
   // if (arrangements + arrangements2 > 10000) { cout << arrangements + arrangements2 << endl; }
    return arrangements + arrangements2;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    ifstream input(argv[1]);
    string line;
    vector <string> vecInput;
    long long ans = 0;

    if (!input.is_open()) {
        std::cout << "Failed to open input file \n";
        exit(-1);
    }

    while (getline(input, line)) {
        vecInput.push_back(line);
    } //read input

    for (int i = 0; i < vecInput.size(); i++) {

        vector<string> lr = customSplit(vecInput[i], ' ');
        string r = lr[1];
        vector<string> groups = customSplit(r, ',');
        removeSpaces(groups);
        string springs = lr[0];
        vector<int> realGroups;
        for (int j = 0; j < groups.size(); j++) {
            realGroups.push_back(stoi(groups[j]));
        }

        string newSprings;
        for (int j = 0; j < 4; j++) {
            newSprings += springs;
            newSprings += "?";
        }
        newSprings += springs;
        int size = realGroups.size();
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < size; k++) {
                realGroups.push_back(realGroups[k]);
            }
        }


        int lineArrangements = recursion(newSprings, realGroups);
        ans += lineArrangements;
        cout << i << endl;
    }
   
    std::cout << ans << endl;

    input.close();
}



