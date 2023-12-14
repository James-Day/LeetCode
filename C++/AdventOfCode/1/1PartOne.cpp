#include <iostream>
#include <fstream>
#include <string>

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
                break;
            }
        }

        for (int i = line.size() - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                rightMost += line[i];
                break;
            }
        }
        sum += std::stoi(leftMost + rightMost);
    }

    std::cout << sum << std::endl;

    input.close();

}