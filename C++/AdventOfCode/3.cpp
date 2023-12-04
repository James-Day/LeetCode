#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int checkSides(int i, int j, vector<string>& map) {
   
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
    /*if (i + 1 < map.size() - 1) {
        //check below
        if (map[i+1][j] != '.' && !isdigit(map[i+1][j])) {
            charFound = true;
        }
        
        if (j - 1 >= 0) {
            //check left 
            if (map[i + 1][j - 1] != '.' && !isdigit(map[i + 1][j - 1])) {
                charFound = true;
            }
        }
        if (j + 1 < map[i + 1].size() - 1) {
            //check right
            if (map[i + 1][j + 1] != '.' && !isdigit(map[i + 1][j + 1])) {
                charFound = true;
            }
        }
    }
    if (i - 1 >= 0 ) {
        //check above
        if (map[i - 1][j] != '.' && !isdigit(map[i - 1][j])) {
            charFound = true;
        }
        if (j - 1 >= 0) {
            //check left
            if (map[i - 1][j - 1] != '.' && !isdigit(map[i - 1][j - 1])) {
                charFound = true;
            }
        }
        if (j + 1 < map[i - 1].size() - 1) {
            //check right
            if (map[i - 1][j + 1] != '.' && !isdigit(map[i - 1][j + 1])) {
                charFound = true;
            }
        }
    }
    if (j + 1 < map[i].size() - 1) {
        //check right
        if (map[i][j + 1] != '.' && !isdigit(map[i][j + 1])) {
            charFound = true;
        }
    }
    if (j - 1 >= 0) {
        //check left
        if (map[i][j - 1] != '.' && !isdigit(map[i][j - 1])) {
            charFound = true;
        }
    }*/
    return false;
}

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
    }int j = 0;
    while (getline(input, line)) {
        string a;
        for (int i = 0; i < line.size(); i++) {
            a += line[i];
        }
        map.push_back(a);
        j++;
    }

    for (int i = 0; i < map.size(); i++) {
        int mult = 0;
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '*') {
                if (checkSides(i, j, map) != -1) {
                    mult = checkSides(i, j, map);
                    ans += mult;
                    continue;
                }
            }
           
        }
    }



    cout << ans;

    input.close();
  
}