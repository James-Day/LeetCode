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
//CHANGE pairs to struct to make more sense
cardToNum cardValue[] = {
    {'J', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'Q', 11},
    {'K', 12},
    {'A', 13},
};

cardToNum lookupType[] = {
    {'5', 6},
    {'4', 5},
    {'F', 4},
    {'3', 3},
    {'2', 2},
    {'1', 1},
    {'H', 0},
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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    ifstream input(argv[1]);
    string line;
    vector <string> vecInput;
    vector<string> orderVals;
    long long ans = 0;

    if (!input.is_open()) {
        cout << "Failed to open input file \n";
        exit(-1);
    }

    while (getline(input, line)) {
        vecInput.push_back(line);
    } //read input

    vector<vector<string>> list;
    for (int i = 0; i < vecInput.size(); i++) {
        list.push_back(customSplit(vecInput[i], ' '));
    }
    vector<vector<int>> difs;
    for (int i = 0; i < list.size(); i++) {
        vector<int> a;
        for (int j = 0; j < list[i].size(); j++) {
            a.push_back(stoi(list[i][j]));
        }
        difs.push_back(a);
        a.clear();
        bool cont = true;
        int c = 0;
        while (cont) {
            for (int j = 1; j < difs[c].size(); j++) {
                a.push_back(difs[c][j] - difs[c][j - 1]);
            }
            difs.push_back(a);
            a.clear();
            cont = false;
            c++;
            for (int  m = 0; m < difs[c].size(); m++) {
                if (difs[c][m] != 0) {
                    cont = true;
                }
            }
        }
        for (int j = difs.size() - 1; j > 0; j--) {
            difs[j - 1].push_back(difs[j - 1][difs[j - 1].size()-1] + difs[j][difs[j].size()-1]);

            //std::vector::insert(begin(), 1, val) // should have used this, even though it's inefficient
            //difs[j - 1].push_back(difs[j - 1][0] - difs[j][difs[j].size() - 1]);  only line change for part 2
        }
        ans += difs[0][difs[0].size() - 1];
        difs.clear();
    }
       
    cout << ans;

    input.close();
}



