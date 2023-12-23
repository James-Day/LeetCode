#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <sstream>
#include <queue>

using namespace std;
//UTIL
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
vector<string> customSplit2(string input, char delimiter, char delim2) {
    vector<string> res;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= input.size(); i++) {
        if ((input[i] == delimiter || i == input.size()) || input[i] == delim2) {
            endIndex = i;
            string temp;
            temp.append(input, startIndex, endIndex - startIndex);
            res.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return res;
}
void removeSpaces(vector<string>& input) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == "") {
            input.erase(input.begin() + i);
        }
    }
}
vector<int> stringVecToIntVec(vector<string>& input) {
    vector<int> res;
    for (string s : input) {
        res.push_back(stoi(s));
    }
    return res;
}
vector<long long> stringVecToLLVec(vector<string>& input) {
    vector<long long> res;
    for (string s : input) {
        res.push_back(stoll(s));
    }
    return res;
}
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int cols = matrix[0].size();
    int rows = matrix.size();
    vector<vector<int>>ans(cols, vector<int>(rows, 0));

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            ans[i][j] = (matrix[j][i]);
        }
    }
    return ans;
}
//UTIL
enum Direction {

    None, North, South, East, West
};

struct Position {
    int i;
    int j;
    int movesSoFar;
    Direction From;
    vector<pair<int, int>> seen;
};
bool vised[200][200];

void findLongestPath(vector<string>& map, Position p, vector<int>& hikes) { 
    vector<Position> stack;
    stack.push_back(p);
    while (!stack.empty()) {
        p = stack.back();
        stack.pop_back();
        bool cont = false;
        if (vised[p.i][p.j]) continue;
        for (int i = 0; i < p.seen.size(); i++) {
            if (p.seen[i].first == p.i && p.seen[i].second == p.j) cont = true;
        }
        if (cont) continue;
        p.seen.push_back({p.i, p.j});
        if (p.i == map.size() - 1) {
            hikes.push_back(p.movesSoFar);
            sort(hikes.begin(), hikes.end());
        }
        Position p2 = p;
        p2.movesSoFar++;
        vised[p.i][p.j] = 1;
        if (map[p.i][p.j] == '.') {
           // map[p.i][p.j] = '#';
            if (p.From != South && p.i + 1 < map.size() && map[p.i + 1][p.j] != '#') { //SOUTH
                p2.i = p2.i + 1;
                p2.From = North; // coming from the north.
                stack.push_back(p2);
                //findLongestPath(map, p2, hikes);
            }
            p2 = p; // clean this up
            p2.movesSoFar++;

            if (p.From != North && p.i - 1 >= 0 && map[p.i - 1][p.j] != '#') { //NORTH
                p2.i = p2.i - 1;
                p2.From = South; // coming from the South.
                //findLongestPath(map, p2, hikes);
                stack.push_back(p2);
            }
            p2 = p;
            p2.movesSoFar++;

            if (p.From != East && p.j + 1 < map[p.i].size() && map[p.i][p.j + 1] != '#') { //East
                p2.j = p2.j + 1;
                p2.From = West; // coming from the West.
                //findLongestPath(map, p2, hikes);
                stack.push_back(p2);
            }
            p2 = p;
            p2.movesSoFar++;

            if (p.From != West && p.j - 1 >= 0 && map[p.i][p.j - 1] != '#') { //West
                p2.j = p2.j - 1;
                p2.From = East; // coming from the East.
                //findLongestPath(map, p2, hikes);
                stack.push_back(p2);
            }
        }
        vised[p.i][p.j] = 0;
       // map[p.i][p.j] = '.';

        /*
        else if (map[p.i][p.j] == '>') {
            if (p.From != East && p.j + 1 < map[p.i].size() && map[p.i][p.j + 1] != '#') { //East
                p2.j = p2.j + 1;
                p2.From = West; // coming from the north.
                stack.push_back(p2);
            }
        }
        else if (map[p.i][p.j] == '<') {
            if (p.From != West && p.j - 1 >= 0 && map[p.i][p.j - 1] != '#') { //West
                p2.j = p2.j - 1;
                p2.From = East; // coming from the north.
                stack.push_back(p2);
            }
        }
        else if (map[p.i][p.j] == '^') {
            if (p.From != North && p.i - 1 >= 0 && map[p.i - 1][p.j] != '#') { //NORTH
                p2.i = p2.i - 1;
                p2.From = South; // coming from the north.
                stack.push_back(p2);
            }
        }
        else if (map[p.i][p.j] == 'v') {
            if (p.From != South && p.i + 1 < map.size() && map[p.i + 1][p.j] != '#') { //SOUTH
                p2.i = p2.i + 1;
                p2.From = North; // coming from the north.
                stack.push_back(p2);
            }
        }
        */
    }

}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    ifstream input(argv[1]);
    string line;
    vector <string> vecInput; // change name to graph
    long long ans = 0;

    if (!input.is_open()) {
        std::cout << "Failed to open input file \n";
        exit(-1);
    }

    while (getline(input, line)) {
        vecInput.push_back(line);
    } 
    input.close();
    

    vector<pair<int, int>> seen;
    Position p = { 0,1,0, North, seen}; // find the s to find starting spot
    vector<int> hikes;
    for (int i = 0; i < vecInput.size(); i++) {
        for (int j = 0; j < vecInput[i].size(); j++) {
            if (vecInput[i][j] == '^') vecInput[i][j] = '.';
            if (vecInput[i][j] == '>') vecInput[i][j] = '.';
            if (vecInput[i][j] == '<') vecInput[i][j] = '.';
            if (vecInput[i][j] == 'v') vecInput[i][j] = '.';
        }
    }

    findLongestPath(vecInput, p, hikes);

    int ans2 = 0;
    for (int i = 0; i < hikes.size(); i++) {
        ans2 = max(hikes[i], ans2);
    }
    cout << ans2;
    

}



