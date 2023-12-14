#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    ifstream input(argv[1]);
    string line;
    vector <string> vecInput;
    int ans = 0;

    if (!input.is_open()) {
        cout << "Failed to open input file \n";
        exit(-1);
    }

    while (getline(input, line)) {
        vecInput.push_back(line);
    } //read input

    for (int i = 0; i < vecInput.size(); i++) {
        vector<string> cardNums = customSplit(vecInput[i],':');
        vector<string> halfs = customSplit(cardNums[1], '|');
        vector<string> winningNums = customSplit(halfs[0], ' ');
        winningNums = removeSpaces(winningNums);
        vector<string> ourNums = customSplit(halfs[1], ' ');
        ourNums = removeSpaces(ourNums);

        unordered_set<int> win;
        for (int j = 0; j < winningNums.size(); j++) {
            win.insert(stoi(winningNums[j]));
        }

        int matches = 0;

        for (int j = 0; j < ourNums.size(); j++) {
            if (win.contains(stoi(ourNums[j]))) matches++;
        }
        ans += (pow(2, matches - 1));

    }



    cout << ans;

    input.close();

}