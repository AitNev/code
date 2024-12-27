#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0); // Initialize the vector
        stack<pair<int, int>> myStack; // Temperature, Index

        for (int i = temperatures.size()-1; i >= 0; i--) {
            int temperature = temperatures[i];
            while (!myStack.empty()){
                if (myStack.top().first > temperature) {
                    answer[i] = myStack.top().second - i;
                    break;
                }else myStack.pop();
            }
            myStack.push({temperature, i});
        }
        return answer;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result1 = solution.dailyTemperatures(temperatures1);

    cout << "Test Case 1: ";
    for (int val : result1) {
        printf("%i ", val);
    }
    cout << " // Expected: 1 1 4 2 1 1 0 0" << endl;

    // Test case 2
    vector<int> temperatures2 = {30, 40, 50, 60};
    vector<int> result2 = solution.dailyTemperatures(temperatures2);

    cout << "Test Case 2: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << " // Expected: 1 1 1 0" << endl;

    // Test case 3
    vector<int> temperatures3 = {30, 60, 90};
    vector<int> result3 = solution.dailyTemperatures(temperatures3);

    cout << "Test Case 3: ";
    for (int val : result3) {
        cout << val << " ";
    }
    cout << " // Expected: 1 1 0" << endl;

    return 0;
}
