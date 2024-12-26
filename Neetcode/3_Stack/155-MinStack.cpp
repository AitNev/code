#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<pair<int, int>> myStack;

    MinStack() {

    }

    // Store pairs the usual stack, the current minimum
    // Takes twice the space, but it retrieves the values in O(1)
    void push(int val) {
        if (myStack.empty()){
            myStack.push({val, val});
        }else{
            int min = myStack.top().second;
            myStack.push({val, ((min < val)? min: val)});
        }
    }

    void pop() {
        myStack.pop();
    }

    int top() {
        return myStack.top().first;
    }

    int getMin() {
        return myStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minStack;

    // Test sequence from the example
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    // Check the minimum value
    cout << "Current minimum: " << minStack.getMin() << endl; // Expected output: -3

    // Remove the top element
    minStack.pop();

    // Check the top element
    cout << "Top element after pop: " << minStack.top() << endl; // Expected output: 0

    // Check the minimum value again
    cout << "Current minimum: " << minStack.getMin() << endl; // Expected output: -2

    // Additional operations
    minStack.push(-1);
    cout << "Top element after pushing -1: " << minStack.top() << endl; // Expected output: -1
    cout << "Current minimum: " << minStack.getMin() << endl; // Expected output: -2

    return 0;
}

