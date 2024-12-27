#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        auto b = s.begin(), e = s.end() - 1;

        while (b < e) {
            // Clean spaces and stuff
            while (b < e && !isalnum(*b)) b++;
            while (b < e && !isalnum(*e)) e--;
            // Check on lowercase
            if (tolower(*b) != tolower(*e)) return false;
            b++;
            e--;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1 = "A man, a plan, a canal: Panama";
    bool expected1 = true;
    bool result1 = solution.isPalindrome(s1);
    cout << "Result for Example 1: " << result1 << endl;
    assert(result1 == expected1);
    cout << "Example 1 passed!" << endl;

    // Example 2
    string s2 = "race a car";
    bool expected2 = false;
    bool result2 = solution.isPalindrome(s2);
    cout << "Result for Example 2: " << result2 << endl;
    assert(result2 == expected2);
    cout << "Example 2 passed!" << endl;

    // Example 3
    string s3 = " ";
    bool expected3 = true;
    bool result3 = solution.isPalindrome(s3);
    cout << "Result for Example 3: " << result3 << endl;
    assert(result3 == expected3);
    cout << "Example 3 passed!" << endl;

    cout << "All tests passed!" << endl;
    return 0;
}
