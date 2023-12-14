#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool checkSides(int i, int j, vector<string>& map) {
    int a = map.size(); // convert uint to int
    for (int k = i - 1; k < a && k <= i + 1; k++) {
        int b = map[i].size(); // convert uint to int


        for (int p = j - 1; p < b && p <= j + 1; p++) {
            if (k == i && p == j) {
                continue;
            }
            if (k < 0 || p < 0) {
                continue;
            }
            if (!isdigit(map[k][p]) && map[k][p] != '.') return true;
        }
    }
    return false;
}

/*int checkSides(int i, int j, vector<string>& map) {

    int found = 0;
    int num1 = 0;
    int num2 = 0;
    int a = map.size();
    for (int k = i - 1; k < a && k <= i + 1 ; k++) {
        int b = map[i].size();

        bool newNum = true;

        for (int p = j - 1; p < b && p <= j + 1; p++) {
            if (k == i && p == j) {
                newNum = true;
                continue;
            }
            if (k < 0 || p < 0) {
                continue;
            }
            if (isdigit(map[k][p])) {
                if (newNum) {
                    found++;
                    int m = p;
                    int n = p;
                    for (; m >= 0 && isdigit(map[k][m]); m--) {

                    }
                    for (; n <= map[k].size() && isdigit(map[k][n]); n++) {
                    }
                    if (num1 == 0) {
                        if (n == map[k].size()) {
                            num1 = stoi(map[k].substr(m + 1));
                        }
                        else num1 = stoi(map[k].substr(m + 1, n - m));
                    }
                    else {
                        if (n == map[k].size()) {
                            num2 = stoi(map[k].substr(m + 1));
                        }
                        else num2 = stoi(map[k].substr(m + 1, n - m));
                    }

                }
                newNum = false;
            }
            else {
                newNum = true;
            }

        }

    }
    if (found > 2) return -1;
    if (found < 2) return -1;
    cout << endl;
    cout << "NUM 1: " << num1 << endl;
    cout << "NUM 2: " << num2 << endl;

    return num1 * num2;
}*/

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    ifstream input(argv[1]);
    string line;
    int ans = 0;

    vector<string> map;


    if (!input.is_open()) {
        cout << "Failed to open input file \n";
        exit(-1);
    }
    int j = 0;
    while (getline(input, line)) {
        map.push_back(line);
        j++;
    }

    bool touchingSymbol = false;
    string curNum = "";
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (isdigit(map[i][j])) { 
                curNum += map[i][j];
                if (checkSides(i, j, map)) {
                    touchingSymbol = true;
                    continue;
                }
            }
            else if ( curNum != "") {
                if(touchingSymbol) ans += stoi(curNum);
                curNum = "";
                touchingSymbol = false;
            }
        }
    }



    cout << ans;

    input.close();

}