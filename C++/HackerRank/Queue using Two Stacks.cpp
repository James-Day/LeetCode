#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T> class Queue {
public:
    void enqueue(T val) {
        stack1.push_back(val);
    }
    const T dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push_back(stack1.back());
                stack1.pop_back();
            }
        }
        T ret = stack2.back();
        stack2.pop_back();
        return ret;
    }
    void printPopFront() {
        T print = (stack2.empty()) ? stack1.front() : stack2.back();
        cout << print << endl;
    }
private:
    vector<int> stack1;
    vector<int> stack2;
};

int main() {
    Queue<int> ans;
    int queries = 0;
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        int operation = 0;
        cin >> operation;
        switch (operation) {
        case 1: {
            int val = 0;
            cin >> val;
            ans.enqueue(val);
            break;
        }
        case 2: {
            ans.dequeue();
            break;
        }
        case 3: {
            ans.printPopFront();
            break;
        }
        }

    }
    return 0;
}
