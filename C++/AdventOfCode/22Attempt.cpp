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


struct point {
    int x, y, z;
};
struct Brick {
    point One;
    point Two;
};
bool myFunction(Brick b1, Brick b2) {
    return b1.Two.z < b1.Two.z;
}
//Towards the end I had some overflow issue, I believe it was with calculating the area, so i made everything long long, obviously this is not a good implementation, I'll come back and clean it up




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
    
    vector<vector<vector<char>>> space(10, vector<vector<char>> (3, vector<char> (3, '.')));
    vector<Brick> bricks;
    for (int i = 0; i < vecInput.size(); i++) {
        vector<string>split = customSplit(vecInput[i], '~');
        vector<string> pointOneSplit = customSplit(split[0], ',');
        vector<string> pointTwoSplit = customSplit(split[1], ',');
        point p1 = { stoi(pointOneSplit[0]), stoi(pointOneSplit[1]), stoi(pointOneSplit[2]) };
        point p2 = { stoi(pointTwoSplit[0]), stoi(pointTwoSplit[1]), stoi(pointTwoSplit[2]) };
        Brick brick = { p1, p2 };
        bricks.push_back(brick);
    }

    sort(bricks.begin(), bricks.end(), myFunction);


    for (Brick b : bricks) {

        for (int i = b.One.x; i <= b.Two.x; i++) {
            for (int j = b.One.y; j <= b.Two.y; j++) {
                for (int k = b.One.z; k <= b.Two.z; k++) {
                    space[k][j][i] = 'b';
                }
            }
        }
    }
    for (int i  = 0; i < space.size(); i++) {
        for (int j = 0; j < space[0].size(); j++) {
            for (int k = 0; k < space[0][0].size(); k++) {
                cout << space[i][j][k];
            }
            cout << endl;
        }
        cout << "---" << endl;
    }
    
    //let bricks fall
    cout << ans;


}



