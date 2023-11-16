/*Easiest solution*/
#include <vector>
using namespace std;
class MinStack {
public:

    MinStack() {
    }

    void push(int val) {
        stack.push_back({ val,min(val,getMin()) });
    }

    void pop() {
        stack.pop_back();
    }

    int top() {
        return stack.back().first;
    }

    int getMin() {
        if (stack.empty()) {
            return INT_MAX;
        }
        return stack.back().second;
    }
private:
    vector<pair<int, int>> stack;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 // This is probablly what they were expecting??
 /*
 class MinStack {
public:

    struct node {
        int val;
        int min;
    };

    MinStack() {
        size = 1;
        i = 0;
        stack = new node[size];
    }
    
    void push(int val) {
      if(i >= size){
          //resize
          int newSize = size * 2;
          node* newStack = new node[newSize];
          for(int j = 0; j < size; j++){
              newStack[j] = stack[j];
          }
          size *= 2;
          delete[] stack;
          stack = newStack;
      }
      node newNode;
      newNode.val = val;
      newNode.min = min(getMin(), val);
      stack[i] =  newNode;
      i++;
    }
    
    void pop() {
        i--;
    }
    
    int top() {
        return stack[i - 1].val;
    }
    
    int getMin() {
        if(i == 0){
            return INT_MAX;
        }
     return stack[i - 1].min;
    }
    private:
   
    //node* stack[];
    node* stack;
    int size;
    int i;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 */