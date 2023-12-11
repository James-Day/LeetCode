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
 void expandColumn(vector<string> &map, int j) {
     for (int k = 0; k < map.size(); k++) {
         map[k].insert(j,1000000,'.');
     }

}
void expandRow(vector<string> &map, int i) {
    string add = "";
    for (int k = 0; k < map[0].size(); k++) {
        add += ".";     //better way to do this?
    }
    for (int l = 0; l < 1000000; l++) {
        map.insert(map.begin() + i, add); // make sure this works
    }


}

int shortestPath(pair<int,int> n1, pair<int,int> n2, vector<string> input) {
    int startx = min(n1.second, n2.second);
    int starty = min(n1.first, n2.first);
    int endx = max(n1.second, n2.second);
    int endy = max(n1.first, n2.first);

    int xDist = 0;

    for (int i = startx; i < endx; i++) {
        bool emptyCol = true;
        for (int j = 0; j < input[i].size(); j++) {
            if (input[j][i] == '#') {
                emptyCol = false;
            }
        }
        if (emptyCol) {
            xDist += 9; // change to 1 mill
        }
        xDist++;
    }

    int yDist = 0;
    for (int i = starty; i < endy; i++) {
        bool emptyRow = true;
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == '#') {
                emptyRow = false;
            }
        }

        if (emptyRow) {
            yDist += 9;
        }
        yDist++;
    }


    return xDist + yDist;
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

    vector<pair<int, int>> galaxies;

    //change to new vector
    for (int i = 0; i < vecInput.size(); i++) {
        for (int j = 0; j < vecInput[i].size(); j++) {
            if (vecInput[i][j] == '#') {
                galaxies.push_back({i,j});
            }
        }
    }
    
    for (int i = 0; i < galaxies.size(); i++) {
        for (int j = i + 1; j < galaxies.size(); j++) {
            ans += shortestPath(galaxies[i], galaxies[j], vecInput);
            
        }
        cout << i << endl;
    }
   
    std::cout << endl << endl << ans << endl;

    input.close();
}



