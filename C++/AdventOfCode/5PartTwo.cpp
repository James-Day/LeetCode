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
//UTIL


class Map{
public:
    Map(string map_str) {
        vector<string> lines = customSplit(map_str, '\n');
        removeSpaces(lines);
        
        for (int i = 1; i < lines.size(); i++) { //start at one to skip description
            vector<string> lineNumsStr = customSplit(lines[i], ' ');
            vector<long long> lineNums= stringVecToLLVec(lineNumsStr);
            //int dest = lineNums[0]; //prob dont need to declare these, but makes it more obvious
            //int source = lineNums[1];
            //int size = lineNums[2];
            rules.push_back(lineNums);
        }
    }
    long long convert(long long inp) {
        for (int i = 0; i < rules.size(); i++) {
            if (inp >= rules[i][1] && inp < rules[i][1] + rules[i][2]) { // definitally should declare these first to make readable
                return rules[i][0] + inp - rules[i][1];
            }
        }
        return inp;
    }
    vector<vector<long long>> rules;
};
class Range { //contains lower bound, but not upper. ex : [10,15)
public:
    Range(long long lower, long long upper) {
        this->lower = lower;
        this->upper = upper;
    }
    pair<long long, long long> repr() {
        return { lower,upper };
    }
    Range intersection(Range other) {
        Range tmp = Range(max(lower, other.lower), min(upper, other.upper)); //this is the range of the intersection
        //if no intersection 
        if (tmp.lower >= tmp.upper) return Range(-1, -1); // invalid range  
        return tmp;
    }
    vector<Range> subtract(Range other) {
        vector<Range> res;
        Range inter = intersection(other);
        if (inter.upper == -1 && inter.lower == -1) {
            res.push_back(Range(lower,upper)); //no intersection
            return res;
        }
        if (inter.lower == lower && inter.upper == upper) { //intersection is entire range
            return res; // empty range
        }
        if (inter.lower == lower) {
            res.push_back (Range(inter.upper, upper));
            return res;
        }
        if (inter.upper == upper) {
            res.push_back(Range(lower,inter.lower));
            return res;
        }
        res.push_back(Range(lower, inter.lower));
        res.push_back(Range(inter.upper, upper));
        return res;
    }
    Range add(long long offset) {
        return Range(lower + offset, upper + offset);
    }
    long long lower;
    long long upper;
};
class p2Solver {
public:
    p2Solver(vector<Map> maps) {
        this->maps = maps;

    }
    void propagate(Range r, int layer) { //layer is which layer of maps we are at
        if (layer == maps.size()) { //finished (this range is locations)
            ans = min(r.lower, ans);
            return;
        }
        for (vector<long long> rule : maps[layer].rules) {
            Range mapRange = Range(rule[1], rule[1] + rule[2]); // rule[1] = source, rule[2] = size, rule[0] = destination
            Range intersection = r.intersection(mapRange);
            if (intersection.lower != -1 && intersection.upper != -1) { //use pointer later?
                propagate(intersection.add(rule[0] - rule[1]), layer + 1);
                vector<Range> sub = r.subtract(mapRange); // could delete and just use intersection variable right?
                if (sub.empty()) return; // we already propagated our entire intersection.
                r = sub[0]; //this will be checked again by the loop.
                if (sub.size() == 2) {
                    propagate(sub[1], layer); //this range could still be affected by a different rule.
                }
            }

        }
        propagate(r, layer + 1);
    }
    vector<Map> maps;
    long long ans = LLONG_MAX;
};


long long getLocation(long long seed, vector<Map> maps) {
    for (Map m: maps) {
        seed = m.convert(seed);
    }
    return seed;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    ifstream input(argv[1]);
    string line;
    vector <string> vecInput;
    long long ans = 0;

    if (!input.is_open()) {
        std::cout << "Failed to open input file \n";
        exit(-1);
    }

    while (getline(input, line)) {
        vecInput.push_back(line);
    } //read input

    vector<string> seedStrings = customSplit(vecInput[0], ' ');
    seedStrings.erase(seedStrings.begin());
    vector<long long> seeds = stringVecToLLVec(seedStrings);
    vecInput.erase(vecInput.begin());
    vecInput.erase(vecInput.begin());

    string curMapping;
    vector<Map> maps;
    for (int i = 0; i < vecInput.size(); i++) {
        while (i  < vecInput.size()  && vecInput[i] != "") {
            curMapping += vecInput[i];
            curMapping += '\n';
            i++;
        }
        Map curMap = Map(curMapping);
        maps.push_back(curMap);
        curMapping = "";
    }
    vector<long long> locations;
    for (long long seed : seeds) {
        locations.push_back(getLocation(seed, maps));
    }
    std::cout << *std::min_element(locations.begin(), locations.end()); //part 1

    //std::cout << ans << endl;

    //part 2
    p2Solver p2 = p2Solver(maps);
    for (int i = 0; i < seeds.size(); i+=2) {
        p2.propagate(Range(seeds[i], seeds[i] + seeds[i + 1]), 0); //start at layer 0
    }
    cout << endl << p2.ans << endl;

    input.close();
}



