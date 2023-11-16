#include <vector>
using namespace std;
//I believe this solution is a bit clearer.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;

        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int r = stack.back();
                stack.pop_back();
                int l = stack.back();
                stack.pop_back();
                stack.push_back(l + r);
            }
            else if (tokens[i] == "-") {
                int r = stack.back();
                stack.pop_back();
                int l = stack.back();
                stack.pop_back();
                stack.push_back(l - r);
            }
            else if (tokens[i] == "*") {
                int r = stack.back();
                stack.pop_back();
                int l = stack.back();
                stack.pop_back();
                stack.push_back(l * r);
            }
            else if (tokens[i] == "/") {
                int r = stack.back();
                stack.pop_back();
                int l = stack.back();
                stack.pop_back();
                stack.push_back(l / r);
            }
            else {
                stack.push_back(stoi(tokens[i]));
            }
        }
        return stack.back();
    }
};


//my original solution, more concise, but I think it's a bit harder to read

/*
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1){
            return stoi(tokens[0]);
        }

        vector<int> stack;
    
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
               int val = stack[stack.size() - 2] + stack[stack.size() - 1];
               stack.pop_back();
               stack[stack.size() - 1] = val;
            }
            else if (tokens[i] == "-"){
               int val = stack[stack.size() - 2] - stack[stack.size() - 1];
               stack.pop_back();
               stack[stack.size() - 1] = val;
            }
            else if (tokens[i] == "*"){
               int val = stack[stack.size() - 2] * stack[stack.size() - 1];
               stack.pop_back();
               stack[stack.size() - 1] = val;
            }
            else if (tokens[i] == "/"){
               int val = stack[stack.size() - 2] / stack[stack.size() - 1];
               stack.pop_back();
               stack[stack.size() - 1] = val;
            }
            else{
                stack.push_back(stoi(tokens[i]));
            }
        }



        return stack.back();

    }
};
*/