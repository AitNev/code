#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, vector<string>> dp;
class Solution {
public:
    // set -- Balanced Binary Search Tree (Red-Black usually)
    // unordered_set -- hash table, used store unique elements

    vector<string> generateParenthesis(int n) {
        if(n == 1) return {"()"};   // Base Case
        if(!dp[n].empty()) return dp[n]; // Save Dynamic Programming Recursions

        unordered_set<string> builder;

        for (int i = 1; i <= n/2; ++i) {
            vector<string> r1 = generateParenthesis(n-i);
            vector<string> r2 = generateParenthesis(i);

            for (string s1:r1) {
                for (string s2:r2) {
                    builder.insert(s1+s2);
                    builder.insert(s2+s1);
                }
                for (int j = 0; j < i; ++j) {
                    s1 = "("+s1+")";
                }
                builder.insert(s1);
            }
        }
        vector<string> answer;
        answer.reserve(builder.size());
        for (string s:builder) {
            answer.push_back(s);
        }

        dp[n] = answer;
        return answer;
    }
private:
//    // Try avoiding duplicates DOESNT WORK!!
//    static bool printEndPair(string& s){
//        int beginning = 0, end = s.size()-1;
//        while (beginning < end){
//            if (end-beginning == 1) return false; // () || ()()() || ()()()()()
//            if(s[beginning] == '(' && s[beginning+1] == ')'){
//                // Need at least a bracket pair at the end
//                if (s[end] == ')' && s[end-1] == '('){
//                    beginning += 2; // Continue loop
//                    end -= 2;
//                }else{  // Dont print duplicated pair
//                    return false;
//                }
//            }else{  // (()) || (()()) || ()(())()
//                return true;
//            }
//        }
//        return false; // ()() || ()()()() || ()()()()()()
//    }
};

int main() {
    Solution solution;

    int n1 = 8;
    vector<string> expected1 = {"((((()))))","(((()())))","(((())()))","(((()))())",
                                "(((())))()","((()(())))","((()()()))","((()())())",
                                "((()()))()","((())(()))","((())()())","((())())()",
                                "((()))(())","((()))()()","(()((())))","(()(()()))",
                                "(()(())())","(()(()))()","(()()(()))","(()()()())",
                                "(()()())()","(()())(())","(()())()()","(())((()))",
                                "(())(()())","(())(())()","(())()(())","(())()()()",
                                "()(((())))","()((()()))","()((())())","()((()))()",
                                "()(()(()))","()(()()())","()(()())()","()(())(())",
                                "()(())()()","()()((()))","()()(()())","()()(())()",
                                "()()()(())","()()()()()"};
    vector<string> result1 = solution.generateParenthesis(n1);

    printf("Result: \n");
    for (string s:result1) {
        printf("%s\n",s.c_str());
    }

    // Convert vectors to unordered sets for comparison
    unordered_set<string> expectedSet1(expected1.begin(), expected1.end());
    unordered_set<string> resultSet1(result1.begin(), result1.end());

    bool test1Passed = true;

    // Check for missing strings
    for (const string& s : expectedSet1) {
        if (resultSet1.find(s) == resultSet1.end()) {
            test1Passed = false;
            cout << "Missing string: " << s << endl;
        }
    }

    // Check for extra strings
    for (const string& s : resultSet1) {
        if (expectedSet1.find(s) == expectedSet1.end()) {
            test1Passed = false;
            cout << "Extra string: " << s << endl;
        }
    }

    if (test1Passed) {
        cout << "Test for n = 3 passed!" << endl;
    } else {
        cout << "Test for n = 3 failed!" << endl;
    }

    return 0;
}