#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct cardToNum {
    char c;
    int num;
};
//CHANGE pairs to struct to make more sense
cardToNum cardValue[] = {
    {'J', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'Q', 11},
    {'K', 12},
    {'A', 13},
};

cardToNum lookupType[] = {
    {'5', 6},
    {'4', 5},
    {'F', 4},
    {'3', 3},
    {'2', 2},
    {'1', 1},
    {'H', 0},
};

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

char handType(string hand) {
    unordered_map<char, int> count;
    if (hand == "JJJJJ") return '5';
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i] != 'J') {
            count[hand[i]]++;
        }
    }
    int highestAgain = 0;
    int highestChar = ' ';
    for (auto i = count.begin(); i != count.end(); i++) {
        if (i->second > highestAgain) {
            highestAgain = i->second;
            highestChar = i->first;
        }
    }
    for (int i = 0; i < hand.size(); i ++) {
        if (hand[i] == 'J') {
            count[highestChar]++;
        }
    }
    int highest = 0;
    for (auto i = count.begin(); i != count.end(); i++) {
        highest = max(highest, i->second);
    }
    if (highest == 5) return '5';
    if (highest == 4) return '4';
    if (highest == 3) {
        for (auto i = count.begin(); i != count.end(); i++) {
            if (i->second == 2) {
                return 'F';
            }
        }
        return '3';
    }
    int pairs = 0;
    for (auto i = count.begin(); i != count.end(); i++) {
        if (i->second == 2) {
            pairs++;
        }
    }
    if (pairs == 2) return '2';
    if (pairs == 1) return '1';
    else return 'H';
}

void sortByCard(vector<pair<string, int>>& handsInBucket) {
    for (int i = 0; i < handsInBucket.size(); i++) {
        for (int j = i + 1; j < handsInBucket.size(); j++) {
            int k = 0;
            while (i != j && k < handsInBucket.size() && handsInBucket[i].first[k] == handsInBucket[j].first[k]) {
                k++;
            }
            int iVal = 0;
            int jVal = 0;
            for (int l = 0; l < 13; l++) {
                if (handsInBucket[i].first[k] == cardValue[l].c) iVal = cardValue[l].num;
                if (handsInBucket[j].first[k] == cardValue[l].c) jVal = cardValue[l].num;
            }
            if (jVal < iVal) {
                pair<string, int> temp = handsInBucket[j];
                handsInBucket[j] = handsInBucket[i];
                handsInBucket[i] = temp;
            }
        }
    }
}

vector<vector<pair<string, int>>> sorting(vector<pair<string, int>> hands, vector<char> types) {
    vector<vector<pair<string, int>>> buckets(7);
    



    for (int i = 0; i < hands.size(); i++) {
        for (int k = 0; k < 7; k++) {
            if (lookupType[k].c == types[i]) {
                buckets[lookupType[k].num].push_back({hands[i].first, hands[i].second});
            }
        }
    }

    for (int i = 0; i < buckets.size(); i++) {
       sortByCard(buckets[i]); //Use sort(buckets[i].begin(), buckets[i].end(), sortByCardAgain); //instead? ******
    }

    int rank = 1;
    for (int i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            cout << buckets[i][j].first << "  rank: " << rank << endl;
            rank++;
        }
    }

    //APPEND ALL THE BUCKETS BACK TOGETHER, return (CHANGE THIS)
    return buckets;
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
    vector<char> types;
    vector<pair<string, int>> hands;


    for (int i = 0; i < vecInput.size(); i++) {
        vector<string>split = customSplit(vecInput[i], ' ');
        string hand = split[0];
        string bid = split[1];
        hands.push_back({ hand, stoi(bid) });
        types.push_back(handType(hand));
    }

    vector<vector<pair<string, int>>> output = sorting(hands, types); 

    int rank = 1;
    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < output[i].size(); j++) {
            if (output[i].size() != 0) {
                ans += (output[i][j].second * rank);
                rank++;
            }
        }
    }
    cout << ans;
    input.close();
}

