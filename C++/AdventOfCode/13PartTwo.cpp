
// RANK: (2849 / 2310)
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
//UTIL

void tiltNorth(vector<string>& input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == 'O') {
                //slide north
                for (int k = i - 1; k >= -1; k--) {
                    if (k < 0 || (input[k][j] == 'O' || input[k][j] == '#')) {
                        input[k + 1][j] = 'O';
                        if (i  != k + 1) {
                            input[i][j] = '.';
                        }
                        break;
                    }
                }
            }
        }
    }
}
void tiltSouth(vector<string>& input) {
    for (int i = input.size()-1; i >= 0; i--) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == 'O') {
                //slide south
                for (int k = i + 1; k <= input.size(); k++) {
                    if (k > input.size() - 1 || (input[k][j] == 'O' || input[k][j] == '#')) {
                        input[k - 1][j] = 'O';
                        if (i != k - 1) {
                            input[i][j] = '.';
                        }
                        break;
                    }
                }
            }
        }
    }
}
void tiltEast(vector<string>& input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = input[i].size() -1 ; j >= 0; j--) {
            if (input[i][j] == 'O') {
                //slide east
                for (int k = j + 1; k <= input[i].size(); k++) {
                    if (k > input[i].size() - 1 || (input[i][k] == 'O' || input[i][k] == '#')) {
                        input[i][k-1] = 'O';
                        if (j != k - 1) {
                            input[i][j] = '.';
                        }
                        break;
                    }
                }
            }
        }
    }
}
void tiltWest(vector<string>& input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == 'O') {
                //slide West
                for (int k = j - 1; k >= -1; k--) {
                    if (k > input.size() || (input[i][k] == 'O' || input[i][k] == '#')) {
                        input[i][k+1] = 'O';
                        if (j != k + 1) {
                            input[i][j] = '.';
                        }
                        break;
                    }
                }
            }
        }
    }
}
long long calculateLoad(vector<string>& input) {
    long long ans = 0;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == 'O') {
                ans += input.size() - i;
            }
        }
    }
    return ans;

}

void cycle(vector<string> & input) {
    tiltNorth(input);
    tiltWest(input);
    tiltSouth(input);
    tiltEast(input);
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

    //tiltNorth(vecInput);
  // cout << calculateLoad(vecInput);
   
   for (int i = 0; i < 1000; i++) {
       cycle(vecInput);
       //if (i % 1000 == 0) cout << i << endl; 
       cout << i << "   " << calculateLoad(vecInput) << endl;

   }
   cycle(vecInput);

    

    input.close();
}



