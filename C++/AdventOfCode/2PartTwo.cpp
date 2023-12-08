#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> customSplit(string input, char delimiter ) {
    vector<string> res;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= input.size(); i ++) {
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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    std::ifstream input(argv[1]);
    std::string line;

    if (!input.is_open()) {
        std::cout << "Failed to open input file \n";
        exit(-1);
    }

    vector<string> inputVec;
    int sum = 0;
    while (std::getline(input, line)) {
        inputVec.push_back(line);
    }

    for (int i = 0; i < inputVec.size(); i++) {
        vector<string> curGame = customSplit(inputVec[i], ':');
        for (int j = 0; j < curGame.size(); j+=2) {
            bool impossible = false;
            vector<string> gameNum = customSplit(curGame[j], ' ');
            int gameNumber = stoi(gameNum[1]);
            string curSets = curGame[j + 1];
            vector<string> sets = customSplit(curSets, ';');
            int redMax = 0;
            int blueMax = 0;
            int greenMax = 0;


            for (int k = 0; k < sets.size(); k++) { // each set
                vector<string> numbersColors = customSplit(sets[k], ' ');
                numbersColors.erase(numbersColors.begin()); //remove empty string
                for (int p = 0; p < numbersColors.size(); p+=2) { // each number and color
                    int num = stoi(numbersColors[p]);
                    string color = numbersColors[p + 1];
                    if (color[color.length() - 1] == ',') color.erase(color.end() - 1); //removes extra commas
                    if (color == "red" && num > redMax) redMax = num;
                    if (color == "green" && num > greenMax) greenMax = num;
                    if (color == "blue" && num > blueMax) blueMax = num;
                }
            }

            if (!impossible) sum += (redMax * blueMax * greenMax);
        }
        cout << endl;
    }
    
    std::cout << sum;

    input.close();

}