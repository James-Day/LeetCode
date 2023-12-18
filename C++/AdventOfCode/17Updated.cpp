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

enum direction {
    Left, Right, Up, Down , Nothing
};

const int MAX_MOVES = 3;
const int V = 13;
pair<int, int> minDistance(vector<vector<int>> dist, vector<vector<bool>> sptSet)
{

    // Initialize min value
    int min = INT_MAX, min_index, min_jindex;

    for (int v = 0; v < V; v++) {          //HARD CODEDED
        for (int j = 0; j < V; j++) {
        if (sptSet[v][j] == false && dist[v][j] <= min)
            min = dist[v][j], min_index = v, min_jindex = j;
        }
    }

    return {min_index, min_jindex };
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

    vector<vector<int>> dist(V, vector<int>(V, 0)); //distance from source to [i][j] //COULD JUST INITIALIZE HERE
    vector<vector<pair<int, direction>>> moveTracker(V, vector<pair<int, direction>>(V, {0, Nothing}));
    vector<vector<bool>> shortestPathTreeSet(V, vector<bool>(V, false)); //will be true if vertex i, j is included in shortest path tree //basically just visited

    for (int i = 0; i < vecInput.size(); i++) {
        for (int j = 0; j < vecInput.size(); j++) { // all this is not needed..
            dist[i][j] = INT_MAX;
            shortestPathTreeSet[i][j] = false; // prob not needed.
            moveTracker[i][j] = { 0 , Nothing }; // maybe make a enum for NOTHING?
        }
    }
    dist[0][0] = 0; // source
    direction dir = Right; // start heading right;
    int movesInARow = 0;

    for (int i = 0; i < vecInput.size(); i++) {
        for (int j = 0; j < vecInput.size(); j++) {
            pair<int, int> u = minDistance(dist, shortestPathTreeSet);//not sure why they call it u
            shortestPathTreeSet[u.first][u.second] = true;
            
            if (i + 1 < vecInput.size()) { // test down //COME BACK AND PUT EVERYTHING IN ONE IF STATEMENT
                if (dist[u.first][u.second] != INT_MAX && !shortestPathTreeSet[u.first+1][u.second] && dist[u.first][u.second] + vecInput[u.first][u.second] < dist[u.first + 1][u.second] && moveTracker[u.first][u.second].first < 3) {
                    dist[u.first + 1][u.second] = dist[u.first][u.second] + (vecInput[u.first][u.second] - '0');
                    if (moveTracker[u.first][u.second].second != Down) {
                        moveTracker[u.first + 1][u.second].first = 0;
                    }
                    moveTracker[u.first + 1][u.second].first = moveTracker[u.first][u.second].first + 1;
                }
            }
            if (i -1 >= 0) { // test up
                if (dist[u.first][u.second] != INT_MAX && !shortestPathTreeSet[i-1][j] && dist[u.first][u.second] + vecInput[u.first][u.second] < dist[i - 1][j]) {
                    dist[i - 1][j] = dist[u.first][u.second] + (vecInput[u.first][u.second] - '0');
                    if (moveTracker[i - 1][j].second != Down) {
                        moveTracker[i - 1][j].first = 0;
                    }
                    moveTracker[i - 1][j].first++;
                }
            }
            if  (j + 1 < vecInput[u.first].size()) { // test right
                if (dist[u.first][u.second] != INT_MAX && !shortestPathTreeSet[i][j+1] && dist[u.first][u.second] + vecInput[u.first][u.second] < dist[i][j + 1]) {
                    dist[i][j + 1] = dist[u.first][u.second] + (vecInput[u.first][u.second] - '0');
                    if (moveTracker[i][j + 1].second != Down) {
                        moveTracker[i][j + 1].first = 0;
                    }
                    moveTracker[i][j + 1].first++;
                }
            }
            if (j - 1 > 0) { // test left
                if (dist[u.first][u.second] != INT_MAX && !shortestPathTreeSet[i][j-1] && dist[u.first][u.second] + vecInput[u.first][u.second] < dist[i][j-1]) {
                    dist[i][j - 1] = dist[u.first][u.second] + (vecInput[u.first][u.second] - '0');
                    if (moveTracker[i][j - 1].second != Down) {
                        moveTracker[i][j - 1].first = 0;
                    }
                    moveTracker[i][j - 1].first++;
                }
            }

                

        }
    }
    cout << dist[V - 1][V - 1];



}



