#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//int checkSides() {

//}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    ifstream input(argv[1]);
    string line;
    int ans = 0;

    vector <pair<string,int>> map;


    if (!input.is_open()) {
        cout << "Failed to open input file \n";
        exit(-1);
    }
    while (getline(input, line)) {
        string a;
        for (int i = 0; i < line.size(); i++) {
            a += line[i];
        }
        map.push_back({a, 1});
   }
    
    for (int i = 0; i < map.size(); i++) {
        unordered_map<int, int> winning;
        winning.clear();
        int matches = 0;

        int curans = 0;
        int j = 0;
        while (map[i].first[j] != ':') {

            j++;
        }

        map[i].first = map[i].first.substr(j + 2);

        j = 0;
        string num = "";
        while (map[i].first[j] != '|') {
            if (isdigit(map[i].first[j])) {
                num += map[i].first[j];
            }
            else {
                if (num != "") {
                    winning[stoi(num)]++;
                }
                num = "";
            }
            j++;
        }

        num = "";
        while (j < map[i].first.size()) {
            if (isdigit(map[i].first[j])) {
                num += map[i].first[j];
            }
            else {
                if (num != "") {
                    if (winning[stoi(num)]) {
                        if (curans == 0) {
                            matches++;
                            curans = 1;
                        }
                        else {
                            matches++;
                            curans *= 2;
                        }
                    }
                }
                num = "";
            }
            j++;
        }

        if (num != "") {
            if (winning[stoi(num)]) {
                if (curans == 0) {
                    matches++;
                    curans = 1;
                }
                else {
                    matches++;
                    curans *= 2;
                }
            }
        }
        num = "";
        while (matches >= 1) {
            map[matches + i].second += map[i].second;
            matches--;
        }
        
        ans += map[i].second;
    }



    cout << ans;

    input.close();
  
}