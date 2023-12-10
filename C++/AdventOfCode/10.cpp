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
    long long ans = 0;

    if (!input.is_open()) {
        std::cout << "Failed to open input file \n";
        exit(-1);
    }

    while (getline(input, line)) {
        vecInput.push_back(line);
    } //read input


    int si = 0;
    int sj = 0;
    for (int i = 0; i < vecInput.size(); i++) {
        for (int j = 0; j < vecInput[i].size(); j++) {
            if (vecInput[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }
    int count = 0;
    bool cont = true;
    vector<pair<int, int>> mainPath;

    bool up = false;
    bool left = false;
    bool right = false;
    bool down = false;
    while (cont) {
        if (vecInput[si][sj] == 'S') {
            si++;
            down = true;
            //right = true;
        }
        else if (vecInput[si][sj] == 'J') {
            if (right) {
                si--;
                down = false;
                right = false;
                left = false;
                up = true;
            }
            else {
                sj--;
                down = false;
                right = false;
                left = true;
                up = false;
            }
        }
        else if (vecInput[si][sj] == 'L') {
            if (down) {
                sj++;
                down = false;
                right = true;
                left = false;
                up = false;
            }
            else {
                down = false;
                right = false;
                left = false;
                up = true;
                si--;
            }
        }
        else if (vecInput[si][sj] == 'F') {
            if (up) {
                sj++;
                down = false;
                right = true;
                left = false;
                up = false;
            }
            else {
                down = true;
                right = false;
                left = false;
                up = false;
                si++;
            }
        }
        else if (vecInput[si][sj] == '7') {
            if (right) {
                si++;
                down = true;
                right = false;
                left = false;
                up = false;
            }
            else {
                sj--;
                left = true;
                up = false;
                down = false;
                right = false;
            }
        }
        else if (vecInput[si][sj] == '|') {
            if (down) {
                si++;
            }
            else {
                si--;
            }
        }
        else if (vecInput[si][sj] == '-') {
            if (right) {
                sj++;
            }
            else {
                sj--;
            }
        }

       mainPath.push_back({si,sj});
        count++;
        if (vecInput[si][sj] == 'S') {
            cont = false;
        }
    }
    std::cout << count/2;
    for (int i = 0; i < vecInput.size(); i++) {
        vector<bool> curRow; //true means enclosed
        for (int j = 0; j < vecInput[i].size(); j++) {
            bool inMain = false;
            for (int k = 0; k < mainPath.size(); k++) {
                if (mainPath[k].first == i && mainPath[k].second == j) {
                    inMain = true;
                }
            }
            if (!inMain) {
                int leftWalls = 0;
                for (int m = 0; m < j; m++) {                    

                    if ((vecInput[i][m] == '|' || vecInput[i][m] == 'L' || vecInput[i][m] == 'J' || vecInput[i][m] == 'S')) {
                        bool inMainAgain = false;
                        for (int l = 0; l < mainPath.size(); l++) {
                            if (mainPath[l].first == i && mainPath[l].second == m) {
                                inMainAgain = true;
                            }
                        }
                        leftWalls += inMainAgain;

                    }
                
                }
                if (leftWalls % 2 == 1) {
                    curRow.push_back(true);
                    cout << "i: " << i << " j: " << j << endl;
                    ans += 1;
                }
                else {
                    curRow.push_back(false);
                }
            }
            else {
                curRow.push_back(false);
            }

        }    
       //std::cout << i << endl;
    }
    std::cout << endl << endl << ans << endl;

    input.close();
}



