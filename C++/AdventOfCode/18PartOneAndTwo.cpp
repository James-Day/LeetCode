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


//Towards the end I had some overflow issue, I believe it was with calculating the area, so i made everything long long, obviously this is not a good implementation, I'll come back and clean it up

class Solver {
public:
    Solver() {
        points.push_back({0,0}); //for now we need to start with this point.
    }
    void addInstruction(string direction, long long length) {
        perimeter += length;
        pair<long, long> move = directions[direction];
        pos.first += (length * move.first);
        pos.second += (length * move.second);
        points.push_back(pos);
    }
    long long solve() {
        long long area = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            pair<long long , long long> pointOne = points[i];
            pair<long long, long long> pointTwo = points[i + 1];
            area += (pointOne.first * pointTwo.second) - (pointOne.second * pointTwo.first); // x1y2 - y1x2
        }
        return abs(area) / 2 + perimeter/2 + 1;
    }

private:
    unordered_map<string, pair<long long , long long>> directions = { {"R", {0,1}}, {"L", {0,-1}}, {"U", {-1,0}}, {"D", {1,0}} };
    vector<pair<long long , long long>> points;
    pair<long long, long long> pos;
    long long perimeter = 0;
};


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
    
    Solver solver1;
    Solver solver2;

    //PART #1
    for (int i = 0; i < vecInput.size(); i++) {
        vector<string> split = customSplit(vecInput[i], ' ');
        solver1.addInstruction(split[0], stoll (split[1]));
    }

    ans = solver1.solve();
    cout << ans << endl;
    ans = 0;

    //PART #2
    for (int i = 0; i < vecInput.size(); i++) {
        vector<string> split = customSplit(vecInput[i], ' ');
        long long directionNumber = split[2][7] - '0';
        stringstream stream ;
        long long convertedLength = 0;
        string length = split[2].substr(2, 5);
        stream << length;
        stream >> std::hex >> convertedLength;

        string direction = "";
        if (directionNumber == 0) direction = "R";
        else if (directionNumber == 1) direction = "D";
        else if (directionNumber == 2) direction = "L";
        else if (directionNumber == 3) direction = "U";


        solver2.addInstruction(direction, convertedLength);
    }
    ans = solver2.solve();

    
    cout << ans;


}



