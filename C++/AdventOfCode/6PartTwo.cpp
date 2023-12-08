#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    ifstream input(argv[1]);
    string line;
    int ans = 1;
    vector<string> vec;


    if (!input.is_open()) {
        cout << "Failed to open input file \n";
        exit(-1);
    }
    while (getline(input, line)) {
        string a;
        for (int i = 0; i < line.size(); i++) {
            a += line[i];
        }
        vec.push_back(a);
   }

    vector<long long> times;
    vector<long long> distance;
    string curNum = "";
    vector<int> answers(4, 0);


        for (int j = 0; j < vec[0].size(); j++) {
            if (isdigit(vec[0][j])) {
                curNum += vec[0][j];
            }
        }
        if (curNum != "") {
            times.push_back(stoll(curNum));
        }
        curNum = "";

        for (int i = 0; i < vec[1].size(); i++) {
            if (isdigit(vec[1][i])) {
                curNum += vec[1][i];
            }
            
             
        }
        if (curNum != "") {
            distance.push_back(stoll(curNum));
        }
        curNum = "";

        for (int i = 0; i < times.size(); i++) {
            for (int j = 1; j < times[i]; j++) {
                if (((times[i] - j) * j) > distance[i]) {
                    answers[i]++;
                }
            }
        }

        for (int b = 0; b < answers.size(); b++) {
            if (answers[b] != 0) {
                ans *= (answers[b]);
            }
        }

        cout << ans;



    input.close();
  
}