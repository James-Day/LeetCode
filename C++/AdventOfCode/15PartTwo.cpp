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

long long Hash(long long curVal, char c) {
    curVal += c;
    curVal *= 17;
    curVal %= 256;
    return curVal;
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
    } 

    vector<vector<pair<string, int>>> map (256, vector<pair<string,int>>()); 
    vector<string> firstSplit = customSplit(vecInput[0], ',');
    for (int i = 0; i < firstSplit.size(); i++) { // use for each loop to clean up
        string temp = "";
        int hash = 0;
        
        if (firstSplit[i][firstSplit[i].size() -1] == '-') {
            temp = firstSplit[i].substr(0, firstSplit[i].size() -1);
            for (int j = 0; j < temp.size(); j++) {
                hash = Hash(hash, temp[j]);
            }
            for (int j = 0; j < map[hash].size(); j++) {
                if (map[hash][j].first == temp) {
                    map[hash].erase(map[hash].begin() + j);
                    break;
                }
            }
        }
        else {
            bool dupe = false;
            temp = firstSplit[i].substr(0, firstSplit[i].size() - 2);
            for (int j = 0; j < temp.size(); j++) {
                hash = Hash(hash, temp[j]);
            }
            for (int j = 0; j < map[hash].size(); j++) {
                if (map[hash][j].first == temp) {
                    dupe = true;
                    map[hash][j].second = stoi(firstSplit[i].substr(firstSplit[i].length() - 1, 1)); //change back to split method
                    break;
                }
            }
            if (!dupe) {
                map[hash].push_back({ temp, stoi(firstSplit[i].substr(firstSplit[i].length() - 1, 1)) });
            }
        }
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            ans += ((i + 1) * (j + 1)) * map[i][j].second;
        }
    }
   
    cout << ans;

    input.close();
}



