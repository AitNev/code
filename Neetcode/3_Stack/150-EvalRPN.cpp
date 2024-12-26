#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        for (string token:tokens){
            if (token == "+" || token == "-" || token == "*" || token == "/"){
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();

                if(token == "+") myStack.push(b+a);
                if(token == "-") myStack.push(b-a);
                if(token == "*") myStack.push(b*a);
                if(token == "/") myStack.push(b/a);
            }else {
                myStack.push(stoi(token));
            }
        }
        return myStack.top();
    }
};

int main() {
    Solution solution;

    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Output 1: " << solution.evalRPN(tokens1) << endl; // Output: 9

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Output 2: " << solution.evalRPN(tokens2) << endl; // Output: 6

    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Output 3: " << solution.evalRPN(tokens3) << endl; // Output: 22

    return 0;
}