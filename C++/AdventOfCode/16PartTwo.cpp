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
enum direction {Left, Right, Up, Down};
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


void Move(int i , int j, vector<vector<bool>>& energized, direction dir, vector<string>& inp, vector<vector<vector<direction>>>& dp) {
    while (true) {
        for (int k = 0; k < dp[i][j].size(); k++) {
            if (dp[i][j][k] == dir)  return; 
        }
        if (dir == Left) {
            if (j - 1 < 0) return;
            dp[i][j].push_back(dir);
            if (inp[i][j - 1] == '.' || inp[i][j - 1] == '-') {
                energized[i][j - 1] = true;
                //Move(i, j-1, energized, dir, inp, dp);
                j -= 1;
                //return;
            }
            else if (inp[i][j - 1] == '\\') { // check this
                energized[i][j - 1] = true;
               // Move(i, j - 1, energized, Up, inp, dp);
               // return;
                j -= 1;
                dir = Up;
            }
            else if (inp[i][j - 1] == '/') { // check this
                energized[i][j - 1] = true;
                //Move(i, j - 1, energized, Down, inp, dp);
                //return;
                j -= 1; 
                dir = Down;
            }
            else { //(inp[i][j - 1] == '|') 
                energized[i][j - 1] = true;
                Move(i, j - 1, energized, Down, inp, dp);
                Move(i, j - 1, energized, Up, inp, dp);
            }

        }
        else if (dir == Right) {
            if (j + 1 >= inp[i].size()) return;
            dp[i][j].push_back(dir);
            if (inp[i][j + 1] == '.' || inp[i][j + 1] == '-') {
                energized[i][j + 1] = true;
                //Move(i, j + 1, energized, dir, inp, dp);
                j += 1;
                //return;
            }
            else if (inp[i][j + 1] == '\\') { // check this
                energized[i][j + 1] = true;
               // Move(i, j + 1, energized, Down, inp, dp);
                //return;
                j += 1;
                dir = Down;
            }
            else if (inp[i][j + 1] == '/') {
                energized[i][j + 1] = true;
              //  Move(i, j + 1, energized, Up, inp, dp);
              //  return; //can prob remove these returns
                j += 1;
                dir = Up;
            }
            else { //(inp[i][j + 1] == '|') 
                energized[i][j + 1] = true;
                Move(i, j + 1, energized, Down, inp, dp);
                Move(i, j + 1, energized, Up, inp, dp);
            }

        }
        else if (dir == Up) {
            if (i - 1 < 0) return;
            dp[i][j].push_back(dir);
            if (inp[i - 1][j] == '.' || inp[i - 1][j] == '|') {
                energized[i - 1][j] = true;
               // Move(i - 1, j, energized, dir, inp, dp);
                //return;
                i -= 1;
            }
            else if (inp[i - 1][j] == '\\') { // check this
                energized[i - 1][j] = true;
                //Move(i - 1, j, energized, Left, inp, dp);
               // return;
                i -= 1;
                dir = Left;
            }
            else if (inp[i - 1][j] == '/') {
                energized[i - 1][j] = true;
                //Move(i - 1, j, energized, Right, inp, dp);
              //  return; //can prob remove these returns
                i -= 1;
                dir = Right;
            }
            else { //(inp[i - 1][j] == '-')
                energized[i - 1][j] = true;
                Move(i - 1, j, energized, Left, inp, dp);
                Move(i - 1, j, energized, Right, inp, dp);
            }

        }
        else {// (dir == Down)
            if (i + 1 >= inp.size()) return;
            dp[i][j].push_back(dir);
            if (inp[i + 1][j] == '.' || inp[i + 1][j] == '|') {
                energized[i + 1][j] = true;
                //Move(i + 1, j, energized, dir, inp, dp);
                //return;
                i += 1;
            }
            else if (inp[i + 1][j] == '\\') { // check this
                energized[i + 1][j] = true;
               // Move(i + 1, j, energized, Right, inp, dp);
                i += 1;
                dir = Right;
               // return;
            }
            else if (inp[i + 1][j] == '/') {
                energized[i + 1][j] = true;
              //  Move(i + 1, j, energized, Left, inp, dp);
              // return; //can prob remove these returns
                i += 1;
                dir = Left;
            }
            else { //(inp[i + 1][j] == '-')
                energized[i + 1][j] = true;
                Move(i + 1, j, energized, Left, inp, dp);
                Move(i + 1, j, energized, Right, inp, dp);
            }
        }
    }

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
    long long realAns = 0;

    if (!input.is_open()) {
        std::cout << "Failed to open input file \n";
        exit(-1);
    }

    while (getline(input, line)) {
        vecInput.push_back(line);
    } 
    input.close();


    for (int k = 0; k < vecInput.size(); k++) {
        vector<vector<bool>> energized(vecInput.size(), vector<bool>(vecInput[0].size(), false));
        vector<vector<vector<direction>>> dp(vecInput.size(), vector<vector<direction>>(vecInput[0].size(), vector<direction>()));
        ans = 0;
        energized[0][k] = true; // start
        Move(0, k, energized, Down, vecInput, dp);

        for (int i = 0; i < energized.size(); i++) {
            for (int j = 0; j < energized[i].size(); j++) {
                ans += (energized[i][j] == true);
            }
        }
        realAns = max(ans, realAns);
    }

    for (int k = 0; k < vecInput.size(); k++) {
        vector<vector<bool>> energized(vecInput.size(), vector<bool>(vecInput[0].size(), false));
        vector<vector<vector<direction>>> dp(vecInput.size(), vector<vector<direction>>(vecInput[0].size(), vector<direction>()));
        ans = 0;
        energized[k][0] = true; // start
        Move(k, 0, energized, Right, vecInput, dp);

        for (int i = 0; i < energized.size(); i++) {
            for (int j = 0; j < energized[i].size(); j++) {
                ans += (energized[i][j] == true);
            }
        }
        realAns = max(ans, realAns);
    }

    cout << realAns ;

}



