#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (char c:s) {    // Push the opening brackets
            if (c == '(' || c == '[' || c == '{')
                myStack.push(c);
            else{   // Lookup for the closing bracket
                if (myStack.empty()) return false;
                if ((c==')'&&myStack.top()=='(') || (c==']'&&myStack.top()=='[')
                    || (c=='}'&&myStack.top()=='{'))
                    myStack.pop();
                else return false;
            }
        }
        return myStack.empty(); // Make sure the stack is empty
    }
};

int main() {
    Solution solution;

    // Test Case 1
    string input1 = "()";
    cout << "Test Case 1: " << solution.isValid(input1) << endl;
    // Expected output: true (1)

    // Test Case 2
    string input2 = "()[]{}";
    cout << "Test Case 2: " << solution.isValid(input2) << endl;
    // Expected output: true (1)

    // Test Case 3
    string input3 = "(]";
    cout << "Test Case 3: " << solution.isValid(input3) << endl;
    // Expected output: false (0)

    // Test Case 4
    string input4 = "([])";
    cout << "Test Case 4: " << solution.isValid(input4) << endl;
    // Expected output: true (1)

    // Test Case 5: Unmatched brackets
    string input5 = "([)]";
    cout << "Test Case 5: " << solution.isValid(input5) << endl;
    // Expected output: false (0)

    // Test Case 6: Empty string
    string input6 = "";
    cout << "Test Case 6: " << solution.isValid(input6) << endl;
    // Expected output: true (1)

    // Test Case 7: Only open brackets
    string input7 = "((((";
    cout << "Test Case 7: " << solution.isValid(input7) << endl;
    // Expected output: false (0)

    // Test Case 8: Only close brackets
    string input8 = "))))";
    cout << "Test Case 8: " << solution.isValid(input8) << endl;
    // Expected output: false (0)

    return 0;
}

