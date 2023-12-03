#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    std::ifstream input(argv[1]);
    std::string line;

    int red = 0;
    int green = 0;
    int blue = 0;
    int ans = 0;


    if (!input.is_open()) {
        std::cout << "Failed to open input file \n";
        exit(-1);
    }
    int sum = 0;
    while (std::getline(input, line)) {
        int i = 0;
        while (line[i] != ' ') i++;
        i++;
        int j = 0;
        while (isdigit(line[i + j])) {
            j++;
        }
        std::string game = line.substr(i,j);
        int gameNUMBER = std::stoi(game); 
        while (line[i] != ' ') i++;
        i++;
        line = line.substr(i, line.size() - i);

        i = 0;
        bool failed = false;
        while (i < line.size()) {
            std::string num = "";
            int curNum = 0;
            while (isdigit(line[i])) {
                num += line[i];
                i++;
            }
            curNum = std::stoi(num);
            line = line.substr(i + 1 , line.size() - i);
            while (line[i] != ',' && line[i] != ';' && line[i] != '\0')i++;
            std::string color = line.substr(0,i);
            
            if (color == "blue") blue = std::max(blue,curNum);
            if (color == "red") red = std::max(red, curNum);
            if (color == "green") green = std::max(green, curNum);
            line = line.substr(i, line.size() - i);
            
            if (line.size() == 0) { 
                break; 
            }
           
            line = line.substr(2, line.size() - 2);
            i = 0;
        }
        ans += (red * blue * green);
        red = 0;
        blue = 0;
        green = 0;
    
    }
    std::cout << ans;

    input.close();
  
}