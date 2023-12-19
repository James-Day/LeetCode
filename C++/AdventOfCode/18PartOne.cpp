#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <regex>
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

void floodFill(vector<vector<char>>& graph, int startI, int startJ, char fillChar, char charToBeFilled) {
    queue<pair<int, int>> floodFillQueue;
    floodFillQueue.push({startI, startJ});
    while (!floodFillQueue.empty()) {
        pair<int, int> ij = floodFillQueue.front();
        floodFillQueue.pop();
        int i = ij.first;
        int j = ij.second;
        if (i >= graph.size() || j >= graph[0].size()) continue;
        if (graph[i][j] != charToBeFilled) continue;

        graph[i][j] = fillChar;
        floodFillQueue.push({ i + 1, j });
        floodFillQueue.push({ i - 1, j });
        floodFillQueue.push({ i, j + 1 });
        floodFillQueue.push({ i, j - 1 });
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
    vector<vector<char>> grid(750, vector<char>(750, '.')); //maybe consider starting in the middle of the array?
    pair<int, int> curPos = { 250,250};
    for (int i = 0; i < vecInput.size(); i++) {
        vector<string> split = customSplit(vecInput[i], ' ');
        int movesLeft = stoi(split[1]);
        if (split[0] == "R") {
            while (movesLeft > 0) {
                curPos.second++;
                grid[curPos.first][curPos.second] = '#';
                movesLeft--;
            }
        }
        else if (split[0] == "L") {
            while (movesLeft > 0) {
                curPos.second--;
                grid[curPos.first][curPos.second] = '#';
                movesLeft--;
            }
        }
        else if (split[0] == "D") {
            while (movesLeft > 0) {
                curPos.first++;
                grid[curPos.first][curPos.second] = '#';
                movesLeft--;
            }
        }
        else { // split[0] == U
            while (movesLeft > 0) {
                curPos.first--;
                grid[curPos.first][curPos.second] = '#';
                movesLeft--;
            }
        }
    }
    floodFill(grid, 246, 246, '#', '.');

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '#') ans++;
        }
    }
    
    cout << ans;


}



