#include <iostream>
#include <fstream>
#include <string>

struct numToNum {
    std::string str;
    int num;
};

const int NUMDIGITS = 10;
numToNum lookUp[] = {
    {"zero", 0}, // didn't actually need 0.
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
};

int isNum(std::string input) {
    for (int i = 0; i < NUMDIGITS; i++) {
        if (lookUp[i].str == input) {
            return i;
        };
    }
    return -1;
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

    int sum = 0;
    while (std::getline(input, line)) {
        std::string leftMost = "";
        std::string rightMost = "";
        for (int i = 0; i < line.size(); i++) {
            if (isdigit(line[i])) {
                leftMost += line[i];
            }
            for (int j = 0; j < i; j++) {
                if (isNum(line.substr(j, i - j + 1)) != -1) {
                    leftMost += std::to_string(isNum(line.substr(j, i - j + 1)));
                }
            }
            if (leftMost != "") break;
        }

        for (int i = line.size() - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                rightMost += line[i];
            }
            for (int j = 0; j < line.size() - i; j++) {
                if (isNum(line.substr(i, line.size() - i - j)) != -1) {
                    rightMost += std::to_string(isNum(line.substr(i, line.size() - i - j)));
                }
            }
            if (rightMost != "") break;
        }
        sum += std::stoi(leftMost + rightMost);
    }

    std::cout << sum << std::endl;

    input.close();

}